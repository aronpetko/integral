#define main vf_hmc_program_main
#include "vf_hmc.cpp"
#undef main

void require(bool ok) { if(!ok) throw std::runtime_error("Test failed"); }
Board position() {
    std::array<unsigned char,32> p{};
    p[0]=16; p[7]=16; // e1, e8
    p[8]=0xd5; p[24]=64; p[26]=9; p[30]=1;
    return Board(p.data());
}
unsigned mv(int from,int to,int flags=0,int promo=0) { return from | (to<<6) | (flags<<14) | (promo<<12); }
int main() {
    for(unsigned h=0;h<256;++h) {
        int expected=0;
        for(unsigned start=14;start<=94;start+=8) if(h>=start) ++expected;
        require(bucket(h)==expected);
    }
    auto b=position(); require(b.ply==16 && !b.in_check());
    b.hmc=13; b.move(mv(4,5)); require(b.hmc==14 && b.kings[0]==5);
    b.move(mv(60,61)); require(b.hmc==15 && b.ply==18);
    b=position(); b.squares[8]=0; ++b.pieces; b.hmc=93;
    b.move(mv(8,24)); require(b.hmc==0 && b.squares[24]==0);
    b=position(); b.squares[0]=3; b.squares[8]=9; b.pieces+=2; b.hmc=55;
    b.move(mv(0,8)); require(b.hmc==0 && b.pieces==3);
    b=position(); b.squares[36]=0; b.squares[35]=8; b.pieces+=2;
    b.move(mv(36,43,1)); require(b.hmc==0 && b.squares[35]==-1 && b.squares[43]==0 && b.pieces==3);
    for(int promo=0;promo<4;++promo) {
        b=position(); b.squares[48]=0; ++b.pieces; b.move(mv(48,56,3,promo));
        require(b.squares[56]==promo+1 && b.hmc==0);
    }
    for(int from : {4,6,5}) for(int rook : {0,7}) {
        b=position(); b.squares[4]=-1; b.squares[from]=5; b.kings[0]=from;
        b.squares[rook]=3; ++b.pieces; b.hmc=10; b.move(mv(from,rook,2));
        require(b.kings[0]==(rook>from ? 6:2) && b.squares[rook>from ? 5:3]==3 && b.hmc==11 && b.pieces==3);
    }
    b=position(); b.squares[12]=11; require(b.in_check());
    b.squares[12]=0; require(!b.in_check());
    b.squares[12]=-1; b.squares[21]=9; require(b.in_check());
    b.squares[21]=-1; b.squares[11]=8; require(b.in_check());
    b=position(); b.squares[13]=10; require(b.in_check());
    require(b.king_bucket(0)==3 && b.king_bucket(1)==3);
    std::cout<<"HMC boundaries, clocks, captures, EP, promotions, Chess960 castles, checks: passed\n";
}
