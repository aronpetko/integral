# Default compiler settings
CC=gcc
CXX=clang++

# Detect the operating system
ifeq ($(OS),Windows_NT)
    detected_OS := Windows
    EXE_EXT := .exe
    BENCH_CMD = bench
    MKDIR = if not exist "$1" mkdir "$1"
    RM = if exist "$1" rmdir /s /q "$1"
    CP = copy /y "$1" "$2"
    RMFILES = del /f /q "$1"
else
    detected_OS := $(shell uname -s)
    EXE_EXT :=
    BENCH_CMD = ./bench
    MKDIR = mkdir -p "$1"
    RM = rm -rf "$1"
    CP = cp "$1" "$2"
    RMFILES = rm -f "$1"
endif

# Build directory
BUILD_DIR = build
PROFILE_DIR = $(BUILD_DIR)/profile

# CMake build options
CMAKE_BUILD_OPTION ?= Release
BUILD_TYPE ?= BUILD_NATIVE

# Path to evaluation file (can be overridden from command line)
EVALFILE ?= ${PROJECT_SOURCE_DIR}/integral.nnue

# Executable name (can be overridden from command line)
EXE ?= integral

.PHONY: all clean debug x86_64_popcnt x86_64_modern x86_64_bmi2 native pgo pgo-clean

# Default target now builds with PGO
all: pgo

# Creates build directory and runs CMake configuration
configure_cmake:
	@$(call MKDIR,$(BUILD_DIR))
	@cd $(BUILD_DIR) && cmake -G "Unix Makefiles" \
		-DCMAKE_BUILD_TYPE=$(CMAKE_BUILD_OPTION) \
		-DCMAKE_C_COMPILER=$(CC) \
		-DCMAKE_CXX_COMPILER=$(CXX) \
		-DEVALFILE=$(EVALFILE) \
		-D$(BUILD_TYPE)=ON \
		$(CMAKE_EXTRA_FLAGS) ..

# PGO build process
pgo: pgo-clean
	@echo "Building with PGO - Generation phase..."
	@$(MAKE) configure_cmake CMAKE_EXTRA_FLAGS="-DENABLE_PGO=ON -DPGO_GENERATE=ON"
	@$(MAKE) -C $(BUILD_DIR) clean
	@$(MAKE) -C $(BUILD_DIR) VERBOSE=1
	@$(MAKE) copy_executable_instrumented
	@echo "Running benchmark to generate profile data..."
	@cd $(PROFILE_DIR) && ../../$(EXE)_instrumented$(EXE_EXT) bench
ifeq ($(CXX),clang++)
	@llvm-profdata merge -output=$(PROFILE_DIR)/default.profdata $(PROFILE_DIR)/default.profraw
endif
	@echo "Building with PGO - Use phase..."
	@$(MAKE) configure_cmake CMAKE_EXTRA_FLAGS="-DENABLE_PGO=ON -DPGO_USE=ON"
	@$(MAKE) -C $(BUILD_DIR) clean
	@$(MAKE) -C $(BUILD_DIR) VERBOSE=1
	@$(MAKE) copy_executable

copy_executable_instrumented:
ifeq ($(detected_OS),Windows)
	@$(call CP,$(BUILD_DIR)\integral$(EXE_EXT),$(EXE)_instrumented$(EXE_EXT))
else
	@$(call CP,$(BUILD_DIR)/integral$(EXE_EXT),$(EXE)_instrumented$(EXE_EXT))
endif

copy_executable:
ifeq ($(BUILD_TYPE),BUILD_DEBUG)
	$(eval EXE_NAME := $(EXE)_debug$(EXE_EXT))
else ifeq ($(BUILD_TYPE),BUILD_X86_64_POPCNT)
	$(eval EXE_NAME := $(EXE)_x86_64_popcnt$(EXE_EXT))
else ifeq ($(BUILD_TYPE),BUILD_X86_64_MODERN)
	$(eval EXE_NAME := $(EXE)_x86_64_modern$(EXE_EXT))
else ifeq ($(BUILD_TYPE),BUILD_X86_64_BMI2)
	$(eval EXE_NAME := $(EXE)_x86_64_bmi2$(EXE_EXT))
else
	$(eval EXE_NAME := $(EXE)$(EXE_EXT))
endif
ifeq ($(detected_OS),Windows)
	@$(call CP,$(BUILD_DIR)\integral$(EXE_EXT),$(EXE_NAME))
else
	@$(call CP,$(BUILD_DIR)/integral$(EXE_EXT),$(EXE_NAME))
endif

pgo-clean:
	@$(call RM,$(PROFILE_DIR))
	@$(call MKDIR,$(PROFILE_DIR))
	@$(call RM,$(BUILD_DIR))
	@$(call MKDIR,$(BUILD_DIR))

clean: pgo-clean
	@$(call RMFILES,$(EXE)*$(EXE_EXT))

# Build variants
debug:
	@echo "Building with debug..."
	@$(MAKE) pgo BUILD_TYPE=BUILD_DEBUG

x86_64_popcnt:
	@echo "Building with x86-64 optimizations..."
	@$(MAKE) pgo BUILD_TYPE=BUILD_X86_64_POPCNT

x86_64_modern:
	@echo "Building with x86-64 modern optimizations..."
	@$(MAKE) pgo BUILD_TYPE=BUILD_X86_64_MODERN

x86_64_bmi2:
	@echo "Building with x86-64 bmi2 optimizations..."
	@$(MAKE) pgo BUILD_TYPE=BUILD_X86_64_BMI2

native:
	@echo "Building with native optimizations..."
	@$(MAKE) pgo BUILD_TYPE=BUILD_NATIVE