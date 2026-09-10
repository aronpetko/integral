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

# Whether or not to build with profile-guided optimizations (PGO=off to disable)
PGO ?= on
PGO_STAGE ?= off
PGO_DIR := $(CURDIR)/$(BUILD_DIR)/pgo
PGO_BENCH_DEPTH ?=

# Debug builds are never worth profiling
ifeq ($(BUILD_TYPE),BUILD_DEBUG)
    USE_PGO := no
else ifneq ($(filter off OFF no NO 0 false FALSE,$(PGO)),)
    USE_PGO := no
else
    USE_PGO := yes
endif

CMAKE_FLAGS := -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=$(CMAKE_BUILD_OPTION) -DCMAKE_C_COMPILER=$(CC) -DCMAKE_CXX_COMPILER=$(CXX) -DEVALFILE=$(EVALFILE) -D$(BUILD_TYPE)=ON -DDATAGEN=$(DATAGEN)

ifeq ($(detected_OS),Windows)
    PGO_DIR_NATIVE := $(subst /,\,$(PGO_DIR))
    PROFILE_RUN := $(BUILD_DIR)\integral$(EXE_EXT) bench $(PGO_BENCH_DEPTH)
else
    PROFILE_RUN := ./$(BUILD_DIR)/integral$(EXE_EXT) bench $(PGO_BENCH_DEPTH)
endif

# Standard targets
.PHONY: all clean debug x86_64 x86_64_popcnt x86_64_bmi2 native compile pgo clean_profile

all:
ifeq ($(USE_PGO),yes)
	@$(MAKE) pgo
else
	@echo Building $(EXE) with $(BUILD_TYPE)...
	@$(MAKE) compile PGO_STAGE=off
endif
	@echo Copying executable...
	@$(MAKE) copy_executable

pgo:
	@echo Building $(EXE) with $(BUILD_TYPE) and profile-guided optimizations...
	@$(MAKE) clean_profile
	@echo [1/3] Building instrumented binary...
	@$(MAKE) compile PGO_STAGE=generate
	@echo [2/3] Collecting profile data...
	@$(PROFILE_RUN)
	@echo [3/3] Rebuilding with the collected profile data...
	@$(MAKE) compile PGO_STAGE=use

compile: $(BUILD_DIR)
	@echo Configuring CMake with BUILD_TYPE=$(BUILD_TYPE), PGO=$(PGO_STAGE)...
	@cd $(BUILD_DIR) && cmake $(CMAKE_FLAGS) -DPGO=$(PGO_STAGE) -DPGO_DIR="$(PGO_DIR)" ..
	@$(MAKE) -C $(BUILD_DIR)

$(BUILD_DIR):
ifeq ($(detected_OS),Windows)
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
else
	@mkdir -p $(BUILD_DIR)
endif

clean_profile:
ifeq ($(detected_OS),Windows)
	@if exist "$(PGO_DIR_NATIVE)" rmdir /s /q "$(PGO_DIR_NATIVE)"
else
	@rm -rf "$(PGO_DIR)"
endif

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
