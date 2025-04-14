# Default compiler settings
CC=gcc
CXX=clang++

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
.PHONY: all clean debug x86_64 x86_64_popcnt x86_64_bmi2 native

# Use profile-guided optimizations
PGO ?= ON

ifeq ($(PGO),ON)
PGO_FLAGS_GEN=-fprofile-generate
PGO_FLAGS_USE=-fprofile-use -fprofile-correction
PGO_DIR=$(BUILD_DIR)/pgo-data

pgo: clean
	@echo "=== PGO: Instrumented Build ==="
	@$(MAKE) all CXXFLAGS="$(PGO_FLAGS_GEN)" PGO_STAGE=GEN
	@echo "=== PGO: Running Training ==="
	@./$(EXE) bench 16
	@echo "=== PGO: Optimized Build ==="
	@$(MAKE) all CXXFLAGS="$(PGO_FLAGS_USE)" PGO_STAGE=USE
else
pgo:
	@echo "PGO disabled. Skipping."
endif

all: $(BUILD_DIR)
ifeq ($(PGO),ON)
	@$(MAKE) pgo_build
else
	@$(MAKE) -C $(BUILD_DIR)
	@$(MAKE) copy_executable
endif

$(BUILD_DIR):
ifeq ($(detected_OS),Windows)
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
else
	@mkdir -p $(BUILD_DIR)
endif
	@echo Configuring CMake with BUILD_TYPE=$(BUILD_TYPE)...
	@cd $(BUILD_DIR) && cmake -G "Unix Makefiles" \
		-DCMAKE_BUILD_TYPE=$(CMAKE_BUILD_OPTION) \
		-DCMAKE_C_COMPILER=$(CC) \
		-DCMAKE_CXX_COMPILER=$(CXX) \
		-DCMAKE_CXX_FLAGS="$(CXXFLAGS)" \
		-DEVALFILE=$(EVALFILE) -D$(BUILD_TYPE)=ON -DDATAGEN=$(DATAGEN) ..

clean:
ifeq ($(detected_OS),Windows)
	@if exist $(BUILD_DIR) rmdir /s /q $(BUILD_DIR)
	@del /f /q $(EXE)*$(EXE_EXT)
else
	@rm -rf $(BUILD_DIR)
	@rm -f $(EXE)*$(EXE_EXT)
endif

pgo_build:
	@echo "=== PGO: Instrumented Build ==="
	@$(MAKE) build_pgo_gen
	@echo "=== PGO: Running Training ==="
	@./$(BUILD_DIR)/integral bench 16
	@echo "=== PGO: Optimized Build ==="
	@$(MAKE) build_pgo_use
	@$(MAKE) copy_executable

build_pgo_gen: $(BUILD_DIR)
	@cd $(BUILD_DIR) && cmake -DCMAKE_CXX_FLAGS="-fprofile-generate" .. && $(MAKE) -j

build_pgo_use: $(BUILD_DIR)
	@cd $(BUILD_DIR) && cmake -DCMAKE_CXX_FLAGS="-fprofile-use -fprofile-correction" .. && $(MAKE) -j

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