# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Produce verbose output by default.
VERBOSE = 1

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:/Coding/integral/build/CMakeFiles/_CMakeLTOTest-CXX/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:/Coding/integral/build/CMakeFiles/_CMakeLTOTest-CXX/bin

# Include any dependencies generated for this target.
include CMakeFiles/boo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/boo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/boo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/boo.dir/flags.make

CMakeFiles/boo.dir/main.cpp.obj: CMakeFiles/boo.dir/flags.make
CMakeFiles/boo.dir/main.cpp.obj: D:/Coding/integral/build/CMakeFiles/_CMakeLTOTest-CXX/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --progress-dir=D:/Coding/integral/build/CMakeFiles/_CMakeLTOTest-CXX/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/boo.dir/main.cpp.obj"
	C:/ProgramData/mingw64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boo.dir/main.cpp.obj -c D:/Coding/integral/build/CMakeFiles/_CMakeLTOTest-CXX/src/main.cpp

CMakeFiles/boo.dir/main.cpp.i: cmake_force
	@echo "Preprocessing CXX source to CMakeFiles/boo.dir/main.cpp.i"
	C:/ProgramData/mingw64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:/Coding/integral/build/CMakeFiles/_CMakeLTOTest-CXX/src/main.cpp > CMakeFiles/boo.dir/main.cpp.i

CMakeFiles/boo.dir/main.cpp.s: cmake_force
	@echo "Compiling CXX source to assembly CMakeFiles/boo.dir/main.cpp.s"
	C:/ProgramData/mingw64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:/Coding/integral/build/CMakeFiles/_CMakeLTOTest-CXX/src/main.cpp -o CMakeFiles/boo.dir/main.cpp.s

# Object files for target boo
boo_OBJECTS = \
"CMakeFiles/boo.dir/main.cpp.obj"

# External object files for target boo
boo_EXTERNAL_OBJECTS =

boo.exe: CMakeFiles/boo.dir/main.cpp.obj
boo.exe: CMakeFiles/boo.dir/build.make
boo.exe: libfoo.a
boo.exe: CMakeFiles/boo.dir/linkLibs.rsp
boo.exe: CMakeFiles/boo.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --progress-dir=D:/Coding/integral/build/CMakeFiles/_CMakeLTOTest-CXX/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable boo.exe"
	"C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/boo.dir/objects.a
	C:/ProgramData/mingw64/mingw64/bin/ar.exe qc CMakeFiles/boo.dir/objects.a @CMakeFiles/boo.dir/objects1.rsp
	C:/ProgramData/mingw64/mingw64/bin/g++.exe -flto=auto -fno-fat-lto-objects -Wl,--whole-archive CMakeFiles/boo.dir/objects.a -Wl,--no-whole-archive -o boo.exe -Wl,--out-implib,libboo.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/boo.dir/linkLibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/boo.dir/build: boo.exe
.PHONY : CMakeFiles/boo.dir/build

CMakeFiles/boo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/boo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/boo.dir/clean

CMakeFiles/boo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" D:/Coding/integral/build/CMakeFiles/_CMakeLTOTest-CXX/src D:/Coding/integral/build/CMakeFiles/_CMakeLTOTest-CXX/src D:/Coding/integral/build/CMakeFiles/_CMakeLTOTest-CXX/bin D:/Coding/integral/build/CMakeFiles/_CMakeLTOTest-CXX/bin D:/Coding/integral/build/CMakeFiles/_CMakeLTOTest-CXX/bin/CMakeFiles/boo.dir/DependInfo.cmake
.PHONY : CMakeFiles/boo.dir/depend

