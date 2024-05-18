# !/bin/sh
if [ -f ../CMakeLists.txt ]; then
    echo "CMakeLists.txt found"
else
    echo "Error: CMakeLists.txt not found"
    exit 1
fi
cd build
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ ..
if [ ! -f Makefile ]; then
    echo "Error: Makefile not generated in build"
    exit 1
fi