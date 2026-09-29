# Default compiler settings
CC ?= gcc
CXX ?= g++

# Detect the operating system
ifeq ($(OS),Windows_NT)
    EXE_EXT := .exe
    # MSYS2/MinGW/Cygwin provide a POSIX shell (bash/sh) even though OS=Windows_NT,
    # so cmd.exe-style recipe syntax (if not exist, del, copy, ...) breaks there.
    # Detect that case via uname and treat it like Unix for recipe purposes.
    UNAME_S := $(shell uname -s 2>/dev/null)
    ifneq (,$(findstring MSYS,$(UNAME_S)))
        detected_OS := Windows_Posix
    else ifneq (,$(findstring MINGW,$(UNAME_S)))
        detected_OS := Windows_Posix
    else ifneq (,$(findstring CYGWIN,$(UNAME_S)))
        detected_OS := Windows_Posix
    else
        detected_OS := Windows
    endif
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

# Extra compiler/linker flags (used for cross-compiling toolchains, e.g. Android NDK)
EXTRA_CXX_FLAGS ?=
EXTRA_LD_FLAGS ?=

# Standard targets
.PHONY: all clean debug x86_64 x86_64_popcnt x86_64_bmi2 native android_aarch64

all: $(BUILD_DIR)
	@echo Building $(EXE) with $(BUILD_TYPE)...
	@"$(MAKE)" -C $(BUILD_DIR)
	@echo Copying executable...
	@"$(MAKE)" copy_executable

$(BUILD_DIR):
ifeq ($(detected_OS),Windows)
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
else
	@mkdir -p $(BUILD_DIR)
endif
	@echo Configuring CMake with BUILD_TYPE=$(BUILD_TYPE)...
	@cd $(BUILD_DIR) && cmake -G "Unix Makefiles" \
		-DCMAKE_BUILD_TYPE=$(CMAKE_BUILD_OPTION) \
		-DCMAKE_C_COMPILER="$(CC)" \
		-DCMAKE_CXX_COMPILER="$(CXX)" \
		-DCMAKE_CXX_FLAGS="$(EXTRA_CXX_FLAGS)" \
		-DCMAKE_EXE_LINKER_FLAGS="$(EXTRA_LD_FLAGS)" \
		-DEVALFILE=$(EVALFILE) \
		-D$(BUILD_TYPE)=ON \
		-DDATAGEN=$(DATAGEN) \
		..

clean:
ifeq ($(detected_OS),Windows)
	@if exist $(BUILD_DIR) rmdir /s /q $(BUILD_DIR)
	@if exist build_host rmdir /s /q build_host
	@del /f /q $(EXE)*$(EXE_EXT) 2>nul || true
else
	@rm -rf $(BUILD_DIR) build_host
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
else ifeq ($(BUILD_TYPE),BUILD_ANDROID_AARCH64)
	$(eval EXE_EXT :=)
	$(eval EXE_NAME := $(EXE)_v8_ja_aarch64)
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
	@"$(MAKE)" all BUILD_TYPE=BUILD_DEBUG

vnni512:
	@echo Building with BUILD_VNNI512
	@"$(MAKE)" all BUILD_TYPE=BUILD_VNNI512

avx512:
	@echo Building with BUILD_AVX512
	@"$(MAKE)" all BUILD_TYPE=BUILD_AVX512

avx2_bmi2:
	@echo Building with BUILD_AVX2_BMI2
	@"$(MAKE)" all BUILD_TYPE=BUILD_AVX2_BMI2

avx2:
	@echo Building with BUILD_AVX2
	@"$(MAKE)" all BUILD_TYPE=BUILD_AVX2

sse41_popcnt:
	@echo Building with BUILD_SSE41_POPCNT
	@"$(MAKE)" all BUILD_TYPE=BUILD_SSE41_POPCNT

native:
	@echo Building with native optimizations...
	@"$(MAKE)" all BUILD_TYPE=BUILD_NATIVE


# ------------------------------------------------------------------
# Android NDK aarch64 – two-stage build
# Stage 1: host (Windows) preprocess that produces aarch64 layout
# Stage 2: real cross-compile of the engine
# ------------------------------------------------------------------
android_aarch64:
	@echo "=== Stage 1: host preprocess (aarch64 network layout) ==="
	@mkdir -p build_host
	@cd build_host && cmake -G "Unix Makefiles" \
		-DCMAKE_BUILD_TYPE=Release \
		-DBUILD_NATIVE=ON \
		-DPRODUCE_AARCH64_NET=ON \
		-DEVALFILE="$(EVALFILE)" \
		..
	@$(MAKE) -C build_host preprocess
	@build_host/preprocess/preprocess.exe \
		"$(if $(EVALFILE),$(EVALFILE),haxorus.nnue)" \
		"build_host/processed_aarch64.nnue"
	@echo "=== Stage 2: cross-compile engine for aarch64 ==="
	@"$(MAKE)" all BUILD_TYPE=BUILD_ANDROID_AARCH64 \
		CC=aarch64-linux-android21-clang \
		CXX=aarch64-linux-android21-clang++ \
		EVALFILE='"$(CURDIR)/build_host/processed_aarch64.nnue"' \
		EXTRA_CXX_FLAGS="-march=armv8-a+fp+simd+crypto+crc -ftree-vectorize -funroll-loops -m64 -stdlib=libc++ -fPIE -static-libstdc++ -std=gnu++20 -flto=auto -Ofast -pipe -finline-functions -pthread -ffast-math -MMD -MP -w -fwrapv -DBUILD_HAS_NEON -fconstexpr-steps=100000000" \
		EXTRA_LD_FLAGS="-lm -latomic -m64 -stdlib=libc++ -fPIE -static-libstdc++ -pie -flto=auto -pthread -Wl,-z,stack-size=8388608"