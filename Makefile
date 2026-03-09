# Default compiler settings
CC ?= gcc
CXX ?= g++

# Detect the operating system
ifeq ($(OS),Windows_NT)
    detected_OS := Windows
    EXE_EXT := .exe
else
    detected_OS := $(shell uname -s)
    EXE_EXT :=
endif

# Build directory
BUILD_DIR=build

# CMake build option
CMAKE_BUILD_OPTION ?= Release
BUILD_TYPE ?= BUILD_NATIVE

# Path to evaluation file (can be overridden from command line)
EVALFILE ?=

# Executable name (can be overridden from command line)
EXE ?= integral

# Whether or not datagen will be used
DATAGEN ?= OFF

# Standard targets
.PHONY: all clean debug x86_64 x86_64_popcnt x86_64_bmi2 native apple_silicon pgo

all: $(BUILD_DIR)
	@echo Building $(EXE) with $(BUILD_TYPE)...
	@$(MAKE) -C $(BUILD_DIR)
	@echo Copying executable...
	@$(MAKE) copy_executable

$(BUILD_DIR):
ifeq ($(detected_OS),Windows)
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
else
	@mkdir -p $(BUILD_DIR)
endif
	@echo Configuring CMake with BUILD_TYPE=$(BUILD_TYPE)...
	@cd $(BUILD_DIR) && cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=$(CMAKE_BUILD_OPTION) -DCMAKE_C_COMPILER=$(CC) -DCMAKE_CXX_COMPILER=$(CXX) -DEVALFILE=$(EVALFILE) -D$(BUILD_TYPE)=ON -DDATAGEN=$(DATAGEN) $(EXTRA_CMAKE_ARGS) ..

clean:
ifeq ($(detected_OS),Windows)
	@if exist $(BUILD_DIR) rmdir /s /q $(BUILD_DIR)
	@del /f /q $(EXE)*$(EXE_EXT)
else
	@rm -rf $(BUILD_DIR)
	@rm -f $(EXE)*$(EXE_EXT)
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
else ifeq ($(BUILD_TYPE),BUILD_APPLE_SILICON)
	$(eval EXE_NAME := $(EXE)_apple_silicon$(EXE_EXT))
else
	$(eval EXE_NAME := $(EXE)$(EXE_EXT))
endif

ifeq ($(detected_OS),Windows)
	@copy $(BUILD_DIR)\integral$(EXE_EXT) $(EXE_NAME)
else
	@cp $(BUILD_DIR)/integral$(EXE_EXT) $(EXE_NAME)
endif

debug:
	@echo Building with debug
	@$(MAKE) all BUILD_TYPE=BUILD_DEBUG

apple_silicon:
	@echo Building for Apple Silicon...
	@$(MAKE) all BUILD_TYPE=BUILD_APPLE_SILICON

apple_pgo:
	@echo Building for Apple Silicon with PGO...
	@$(MAKE) pgo BUILD_TYPE=BUILD_APPLE_SILICON

pgo:
	@echo Starting PGO build...
	@$(MAKE) clean
	@echo Phase 1: Building with instrumentation...
	@mkdir -p $(BUILD_DIR)/pgo_profile
	@echo Configuring CMake with BUILD_TYPE=$(BUILD_TYPE) and USE_PGO_GENERATE=ON...
	@cd $(BUILD_DIR) && cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=$(CMAKE_BUILD_OPTION) -DCMAKE_C_COMPILER=$(CC) -DCMAKE_CXX_COMPILER=$(CXX) -DEVALFILE=$(EVALFILE) -D$(BUILD_TYPE)=ON -DDATAGEN=$(DATAGEN) -DUSE_PGO_GENERATE=ON ..
	@$(MAKE) -C $(BUILD_DIR)
	@$(MAKE) copy_executable
	@echo Phase 2: Generating profiles...
ifeq ($(detected_OS),Windows)
	@$(BUILD_DIR)\integral$(EXE_EXT) bench 12
else
	@$(BUILD_DIR)/integral$(EXE_EXT) bench 12
endif
	@echo Phase 3: Building with profiles...
ifeq ($(detected_OS),Darwin)
	@echo Merging Clang profiles...
	@xcrun llvm-profdata merge -output=$(BUILD_DIR)/pgo_profile/integral.profdata $(BUILD_DIR)/pgo_profile/*.profraw
endif
	@# Preserve the profiles by moving them out of the build directory temporarily
	@mkdir -p pgo_temp
	@cp -r $(BUILD_DIR)/pgo_profile/* pgo_temp/
	@$(MAKE) clean
	@mkdir -p $(BUILD_DIR)/pgo_profile
	@cp -r pgo_temp/* $(BUILD_DIR)/pgo_profile/
	@rm -rf pgo_temp
	@echo Configuring CMake with BUILD_TYPE=$(BUILD_TYPE) and USE_PGO_USE=ON...
	@cd $(BUILD_DIR) && cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=$(CMAKE_BUILD_OPTION) -DCMAKE_C_COMPILER=$(CC) -DCMAKE_CXX_COMPILER=$(CXX) -DEVALFILE=$(EVALFILE) -D$(BUILD_TYPE)=ON -DDATAGEN=$(DATAGEN) -DUSE_PGO_USE=ON ..
	@$(MAKE) -C $(BUILD_DIR)
	@$(MAKE) copy_executable
	@echo PGO build complete.

vnni512:
	@echo Building with BUILD_VNNI512
	@$(MAKE) all BUILD_TYPE=BUILD_VNNI512

avx512:
	@echo Building with BUILD_AVX512
	@$(MAKE) all BUILD_TYPE=BUILD_AVX512

avx2_bmi2:
	@echo Building with BUILD_AVX2_BMI2
	@$(MAKE) all BUILD_TYPE=BUILD_AVX2_BMI2

avx2:
	@echo Building with BUILD_AVX2
	@$(MAKE) all BUILD_TYPE=BUILD_AVX2

sse41_popcnt:
	@echo Building with BUILD_SSE41_POPCNT
	@$(MAKE) all BUILD_TYPE=BUILD_SSE41_POPCNT

native:
	@echo Building with native optimizations...
	@$(MAKE) all BUILD_TYPE=BUILD_NATIVE