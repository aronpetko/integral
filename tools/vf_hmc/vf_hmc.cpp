// Viriformat 2.0.1; matches bullet/examples/advanced_ti as of 2026-09-18.
// Counts pre-move positions, just like loader.rs. No NNUE/engine dependency.
#include <algorithm>
#include <array>
#include <bit>
#include <chrono>
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numeric>
#include <stdexcept>
#include <string>
#include <vector>
#include <omp.h>
#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#else
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#endif

using U64 = std::uint64_t;
using Bytes = const unsigned char*;
constexpr int NB = 12; // fresh + 11 actual features
constexpr int KING_BUCKETS[32] = {0,1,2,3,4,5,6,7,8,8,9,9,10,10,11,11,
                                12,12,12,12,13,13,13,13,14,14,14,14,15,15,15,15};
unsigned u16(Bytes p) { return p[0] | (unsigned(p[1]) << 8); }
unsigned u32(Bytes p) { return u16(p) | (u16(p+2) << 16); }
int bucket(unsigned hmc) { return hmc < 14 ? 0 : 1 + (std::min(hmc,100u)-14)/8; }
std::string label(int b) {
    if (!b) return "0-13 (none)";
    if (b == 11) return "94+";
    return std::to_string(14+(b-1)*8)+"-"+std::to_string(21+(b-1)*8);
}

struct MappedFile {
    Bytes data = nullptr;
    U64 size = 0;
#ifdef _WIN32
    HANDLE file = INVALID_HANDLE_VALUE, mapping = nullptr;
    explicit MappedFile(const std::string& path) {
        file = CreateFileA(path.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr,
                           OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, nullptr);
        if (file == INVALID_HANDLE_VALUE) throw std::runtime_error("Cannot open input");
        LARGE_INTEGER n;
        if (!GetFileSizeEx(file,&n)) { CloseHandle(file); throw std::runtime_error("Cannot get file size"); }
        size = static_cast<U64>(n.QuadPart);
        if (!size) return;
        mapping = CreateFileMappingA(file,nullptr,PAGE_READONLY,0,0,nullptr);
        if (mapping) data = static_cast<Bytes>(MapViewOfFile(mapping,FILE_MAP_READ,0,0,0));
        if (!data) {
            if (mapping) CloseHandle(mapping);
            CloseHandle(file);
            throw std::runtime_error("Cannot map input (use a 64-bit build)");
        }
    }
    ~MappedFile() { if(data) UnmapViewOfFile(data); if(mapping) CloseHandle(mapping); if(file!=INVALID_HANDLE_VALUE) CloseHandle(file); }
#else
    int file = -1;
    explicit MappedFile(const std::string& path) {
        file = open(path.c_str(),O_RDONLY);
        if (file < 0) throw std::runtime_error("Cannot open input");
        struct stat st{};
        if (fstat(file,&st)) { close(file); throw std::runtime_error("Cannot get file size"); }
        size = st.st_size;
        if (!size) return;
        auto p = mmap(nullptr,size,PROT_READ,MAP_PRIVATE,file,0);
        if(p==MAP_FAILED) { close(file); throw std::runtime_error("Cannot map input"); }
        data = static_cast<Bytes>(p);
        madvise(p,size,MADV_SEQUENTIAL);
    }
    ~MappedFile() { if(data) munmap(const_cast<unsigned char*>(data),size); if(file>=0) close(file); }
#endif
    MappedFile(const MappedFile&) = delete;
    MappedFile& operator=(const MappedFile&) = delete;
};

// Mailbox with piece codes pawn=0 .. king=5, black bit=8, empty=-1.
struct Board {
    std::array<int,64> squares;
    int kings[2] = {-1,-1};
    unsigned hmc, ply, side, pieces = 0;
    explicit Board(Bytes p) {
        squares.fill(-1);
        U64 occ = U64(u32(p)) | (U64(u32(p+4))<<32);
        if(std::popcount(occ)>32 || p[30]>2 || (p[24]&127)>64 || !u16(p+26))
            throw std::runtime_error("Invalid packed header");
        while(occ) {
            int sq = std::countr_zero(occ); occ &= occ-1;
            int pc = (p[8+pieces/2] >> (4*(pieces%2))) & 15;
            if((pc&7)==7) throw std::runtime_error("Invalid piece code");
            if((pc&7)==6) pc = (pc&8)|3; // castling rook
            squares[sq]=pc;
            if((pc&7)==5) {
                if(kings[pc>>3]!=-1) throw std::runtime_error("Duplicate king");
                kings[pc>>3]=sq;
            }
            ++pieces;
        }
        if(kings[0]<0 || kings[1]<0) throw std::runtime_error("Missing king");
        side=p[24]>>7; hmc=p[25]; ply=(u16(p+26)-1)*2+side;
    }
    int king_bucket(unsigned color) const {
        int sq=kings[color] ^ (color ? 56 : 0);
        return KING_BUCKETS[(sq/8)*4+std::min(sq%8,7-sq%8)];
    }
    bool in_check() const {
        int sq=kings[side], x=sq%8, y=sq/8, enemy=(1-side)*8;
        auto at = [&](int xx,int yy) { return xx>=0 && xx<8 && yy>=0 && yy<8 ? squares[yy*8+xx] : -1; };
        int pawn_y=y+(side==0 ? 1 : -1);
        if(at(x-1,pawn_y)==enemy || at(x+1,pawn_y)==enemy) return true;
        constexpr int knight[8][2]={{1,2},{2,1},{-1,2},{-2,1},{1,-2},{2,-1},{-1,-2},{-2,-1}};
        for(auto& d:knight) if(at(x+d[0],y+d[1])==enemy+1) return true;
        constexpr int dirs[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        for(int i=0;i<8;++i) {
            int xx=x+dirs[i][0], yy=y+dirs[i][1], dist=1;
            while(xx>=0 && xx<8 && yy>=0 && yy<8) {
                int pc=squares[yy*8+xx];
                if(pc>=0) {
                    if((pc&8)==enemy && ((pc&7)==4 || (pc&7)==(i<4 ? 3 : 2) || (dist==1 && (pc&7)==5))) return true;
                    break;
                }
                xx+=dirs[i][0]; yy+=dirs[i][1]; ++dist;
            }
        }
        return false;
    }
    void move(unsigned m) {
        int from=m&63, to=(m>>6)&63, flags=m>>14, pc=squares[from];
        if(pc<0 || unsigned(pc>>3)!=side || from==to) throw std::runtime_error("Invalid move source");
        if(flags==2) {
            if((pc&7)!=5 || squares[to]!=(int(side)*8+3)) throw std::runtime_error("Invalid castle");
            int rank=from&56, kt=rank+(to>from ? 6:2), rt=rank+(to>from ? 5:3);
            squares[from]=squares[to]=-1;
            squares[kt]=pc; squares[rt]=int(side)*8+3; kings[side]=kt;
            ++hmc;
        } else {
            bool capture=squares[to]>=0;
            if(capture && (unsigned(squares[to]>>3)==side || (squares[to]&7)==5)) throw std::runtime_error("Invalid capture");
            if(flags==1) {
                int cap=to+(side==0 ? -8:8);
                if((pc&7)!=0 || cap<0 || cap>=64 || squares[cap]!=(int(1-side)*8) || capture) throw std::runtime_error("Invalid en passant");
                squares[cap]=-1; --pieces;
            }
            if(flags==3 && (pc&7)!=0) throw std::runtime_error("Invalid promotion");
            hmc=(capture || (pc&7)==0) ? 0 : hmc+1;
            if(capture) --pieces;
            squares[from]=-1;
            squares[to]=flags==3 ? (pc&8)+1+((m>>12)&3) : pc;
            if((pc&7)==5) kings[side]=to;
        }
        ++ply; side^=1;
    }
};

struct Counts {
    std::array<U64,NB> raw{}, eligible{}, games_raw{}, games_eligible{}, max_bucket{};
    U64 king[2][16][11]{}; // STM / NTM, king bucket, HMC feature
    U64 games=0, empty=0;
    void add(const Counts& o) {
        games+=o.games; empty+=o.empty;
        for(int b=0;b<NB;++b) {
            raw[b]+=o.raw[b]; eligible[b]+=o.eligible[b]; games_raw[b]+=o.games_raw[b];
            games_eligible[b]+=o.games_eligible[b]; max_bucket[b]+=o.max_bucket[b];
        }
        for(int p=0;p<2;++p) for(int k=0;k<16;++k) for(int h=0;h<11;++h) king[p][k][h]+=o.king[p][k][h];
    }
};
void process(Bytes p, Bytes end, Counts& c, bool raw_only) {
    Board b(p);
    unsigned raw_seen=0, eligible_seen=0;
    int max_b=-1;
    for(p+=32;p<end-4;p+=4) {
        unsigned m=u16(p), flags=m>>14, to=(m>>6)&63;
        if(!m) throw std::runtime_error("Zero move with nonzero score");
        int eval=static_cast<std::int16_t>(u16(p+2)), h=bucket(b.hmc);
        ++c.raw[h]; raw_seen|=1u<<h; max_b=std::max(max_b,h);
        bool tactical=flags==1 || flags==3 || (flags!=2 && b.squares[to]>=0);
        if(!raw_only && b.ply>=16 && std::abs(eval)<30000 && b.pieces>=4 && !tactical && !b.in_check()) {
            ++c.eligible[h]; eligible_seen|=1u<<h;
            if(h) for(int pov=0;pov<2;++pov) ++c.king[pov][b.king_bucket(b.side^pov)][h-1];
        }
        b.move(m);
    }
    ++c.games;
    if(max_b<0) ++c.empty; else ++c.max_bucket[max_b];
    for(int h=0;h<NB;++h) { c.games_raw[h]+=(raw_seen>>h)&1; c.games_eligible[h]+=(eligible_seen>>h)&1; }
}

double pct(U64 n,U64 d) { return d ? 100.0*double(n)/double(d) : 0; }
U64 number(const std::string& s) {
    if(s.empty() || s.find_first_not_of("0123456789")!=std::string::npos) throw std::runtime_error("Expected positive integer: "+s);
    auto n=std::stoull(s); if(!n) throw std::runtime_error("Expected positive integer: "+s); return n;
}
int main(int argc,char** argv) try {
    std::string path, csv;
    int threads=std::min(16,omp_get_max_threads());
    U64 limit=std::numeric_limits<U64>::max(); bool raw_only=false;
    for(int i=1;i<argc;++i) {
        std::string a=argv[i];
        if(a=="--help" || a=="-h") {
            std::cout<<"Usage: vf_hmc FILE [--threads N] [--max-games N] [--csv PREFIX] [--raw-only]\n"
                     <<"Default: raw + advanced_ti deterministic training filters; random 50% skip reported as expectation.\n";
            return 0;
        }
        if(a=="--raw-only") raw_only=true;
        else if(a=="--threads" || a=="--max-games" || a=="--csv") {
            if(++i==argc) throw std::runtime_error("Missing value for "+a);
            if(a=="--csv") csv=argv[i];
            else if(a=="--max-games") limit=number(argv[i]);
            else { auto n=number(argv[i]); if(n>1024) throw std::runtime_error("Too many threads"); threads=int(n); }
        } else if(a.starts_with("--") || !path.empty()) throw std::runtime_error("Unexpected argument: "+a);
        else path=a;
    }
    if(path.empty()) throw std::runtime_error("Expected FILE; use --help");
    MappedFile file(path); omp_set_num_threads(threads);
    std::vector<Counts> locals(threads);
    U64 pos=0, games=0;
    auto start=std::chrono::steady_clock::now(), last=start;
    std::cerr<<"Scanning "<<file.size<<" bytes with "<<threads<<" threads\n";
    while(pos<file.size && games<limit) {
        std::vector<U64> offsets; offsets.reserve(262145); offsets.push_back(pos);
        while(pos<file.size && offsets.size()<=262144 && games+offsets.size()-1<limit) {
            U64 game_start=pos;
            if(file.size-pos<32) throw std::runtime_error("Truncated header at byte "+std::to_string(pos));
            pos+=32;
            while(true) {
                if(file.size-pos<4) throw std::runtime_error("Missing terminator for game at byte "+std::to_string(game_start));
                bool done=u32(file.data+pos)==0; pos+=4;
                if(done) break;
            }
            offsets.push_back(pos);
        }
        std::string error;
        #pragma omp parallel for schedule(static)
        for(std::int64_t i=0;i<static_cast<std::int64_t>(offsets.size()-1);++i) {
            try { process(file.data+offsets[i],file.data+offsets[i+1],locals[omp_get_thread_num()],raw_only); }
            catch(const std::exception& e) {
                #pragma omp critical
                { if(error.empty()) error=std::string(e.what())+" at game byte "+std::to_string(offsets[i]); }
            }
        }
        if(!error.empty()) throw std::runtime_error(error);
        games+=offsets.size()-1;
        auto now=std::chrono::steady_clock::now();
        if(std::chrono::duration<double>(now-last).count()>=2) {
            double secs=std::chrono::duration<double>(now-start).count();
            std::cerr<<std::fixed<<std::setprecision(1)<<pct(pos,file.size)<<"% | "<<games<<" games | "<<pos/1e6/secs<<" MB/s\n";
            last=now;
        }
    }
    Counts c; for(auto& local:locals) c.add(local);
    U64 raw=std::accumulate(c.raw.begin(),c.raw.end(),U64(0));
    U64 eligible=std::accumulate(c.eligible.begin(),c.eligible.end(),U64(0));
    double secs=std::chrono::duration<double>(std::chrono::steady_clock::now()-start).count();
    std::cout<<std::fixed<<std::setprecision(3)
        <<"Games: "<<c.games<<" (empty: "<<c.empty<<"), positions: "<<raw<<"\n"
        <<"Scanned: "<<pos<<" / "<<file.size<<" bytes; "<<(pos==file.size ? "complete file":"PREFIX ONLY (not a random sample)")<<"\n"
        <<"Time: "<<secs<<" s; "<<pos/1e6/secs<<" MB/s; "<<raw/1e6/secs<<" M positions/s\n";
    if(!raw_only) std::cout<<"Training-eligible: "<<eligible<<"; expected after independent 50% skip: "<<eligible*0.5<<"\n";
    std::cout<<"\n"<<std::setw(14)<<"HMC"<<std::setw(17)<<"Positions"<<std::setw(10)<<"Raw %"
             <<std::setw(17)<<"Games touching"<<std::setw(10)<<"Games %";
    if(!raw_only) std::cout<<std::setw(17)<<"Eligible"<<std::setw(10)<<"Train %"<<std::setw(17)<<"Eligible games";
    std::cout<<std::setw(17)<<"Game maximum"<<"\n";
    for(int h=0;h<NB;++h) {
        std::cout<<std::setw(14)<<label(h)<<std::setw(17)<<c.raw[h]<<std::setw(10)<<pct(c.raw[h],raw)
                 <<std::setw(17)<<c.games_raw[h]<<std::setw(10)<<pct(c.games_raw[h],c.games);
        if(!raw_only) std::cout<<std::setw(17)<<c.eligible[h]<<std::setw(10)<<pct(c.eligible[h],eligible)<<std::setw(17)<<c.games_eligible[h];
        std::cout<<std::setw(17)<<c.max_bucket[h]<<"\n";
    }
    std::cout<<"\nGames touching buckets overlap; game maximum is exclusive, over stored pre-move positions.\n";
    if(!raw_only) std::cout<<"Train % is before random skip and also its expected distribution after skipping.\n";
    if(!csv.empty()) {
        std::ofstream out(csv+".buckets.csv");
        if(!out) throw std::runtime_error("Cannot create bucket CSV");
        out<<"feature,bucket,positions,raw_percent,games_touching,games_percent,game_maximum";
        if(!raw_only) out<<",eligible,training_percent,expected_after_skip,eligible_games";
        out<<"\n"<<std::fixed<<std::setprecision(6);
        for(int h=0;h<NB;++h) {
            out<<h-1<<','<<label(h)<<','<<c.raw[h]<<','<<pct(c.raw[h],raw)<<','<<c.games_raw[h]<<','<<pct(c.games_raw[h],c.games)<<','<<c.max_bucket[h];
            if(!raw_only) out<<','<<c.eligible[h]<<','<<pct(c.eligible[h],eligible)<<','<<c.eligible[h]*0.5<<','<<c.games_eligible[h];
            out<<'\n';
        }
        out.close(); if(!out) throw std::runtime_error("Error writing bucket CSV");
        if(!raw_only) {
            std::ofstream k(csv+".king_hmc.csv");
            if(!k) throw std::runtime_error("Cannot create king CSV");
            k<<"perspective,king_bucket,hmc_feature,input_index,eligible,expected_after_skip\n";
            for(int p=0;p<2;++p) for(int kb=0;kb<16;++kb) for(int h=0;h<11;++h)
                k<<(p ? "ntm":"stm")<<','<<kb<<','<<h<<','<<kb*11+h<<','<<c.king[p][kb][h]<<','<<std::fixed<<std::setprecision(1)<<c.king[p][kb][h]*0.5<<'\n';
            k.close(); if(!k) throw std::runtime_error("Error writing king CSV");
        }
        std::cout<<"CSV prefix: "<<csv<<"\n";
    }
    return 0;
} catch(const std::exception& e) { std::cerr<<"Error: "<<e.what()<<'\n'; return 1; }
