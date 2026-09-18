# Datagen bootstrap

Run from a checkout, or download just the script. A standalone script clones
`aronpetko/integral` into `./integral`; inside a checkout it uses that checkout
without pulling or changing branches.

The script installs missing build dependencies, builds Release with `DATAGEN=ON`,
and downloads [UHO_Lichess_4852_v1.epd](https://github.com/official-stockfish/books)
into `cmake-build-datagen/data`. CMake downloads the required network itself.
The book is reused on subsequent runs.

## Windows

Requires PowerShell and `winget`. Installs MSYS2 and its GCC/CMake/Ninja/Git
packages when needed. Run:

```powershell
powershell -ExecutionPolicy Bypass -File tools/datagen.ps1 -DatagenArgs "games 10000000 threads 12 min_moves 3 max_moves 4 soft_limit 10000 hard_limit 1000000 out dataset book UHO_Lichess_4852_v1.epd"
```

## Ubuntu / Debian (including WSL)

Requires a C++20-capable GCC from your distribution. Installs missing packages
with `apt-get`, using `sudo` when not root. Run:

```bash
bash tools/datagen.sh games 10000000 threads 12 min_moves 3 max_moves 4 soft_limit 10000 hard_limit 1000000 out dataset book UHO_Lichess_4852_v1.epd
```

All arguments after the script name (or the Windows `DatagenArgs` string) become
the arguments of the engine's `datagen` command. The scripts do not enumerate,
validate, or supply defaults for engine options. Include `book` explicitly to
use the downloaded book, or pass your own book. Future engine options work
without changing the scripts.

The engine runs in `cmake-build-datagen/data`, so relative `out` and `book` paths
resolve there. Integral's command parser currently expects paths without spaces.

## Optional setup settings

These environment variables control setup, not datagen:

| Variable | Meaning |
| --- | --- |
| `INTEGRAL_DIR` | Existing checkout or destination for a fresh clone. |
| `INTEGRAL_REF` | Branch/tag for a fresh clone; existing checkouts are unchanged. |
| `BUILD_JOBS` | Parallel compiler jobs; defaults to the CPU count. |
| `MSYS2_ROOT` | Windows MSYS2 location; defaults to `C:\msys64`. |

Once these scripts are pushed to GitHub, download `tools/datagen.sh` or
`tools/datagen.ps1` using the **Raw** button on the desired branch. If that branch
contains changes not on the default branch, set `INTEGRAL_REF` to its name before
running a standalone script.
