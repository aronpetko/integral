@echo off
if exist CMakeLists.txt (
    echo "CMakeLists.txt found"
) else (
    echo "Error: CMakeLists.txt not found"
    exit /b 1
)
cd build
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ ..
if not exist Makefile (
    echo "Error: Makefile not generated in build"
    exit /b 1
)