# Detect the operating system
ifeq ($(OS),Windows_NT)
    detected_OS := Windows
    EXE_EXT := .exe
    NULL_DEVICE := NUL
else
    detected_OS := $(shell uname -s)
    EXE_EXT :=
    NULL_DEVICE := /dev/null
endif

# Default compiler settings, preferring Clang when available
ifeq ($(origin CXX),default)
    CXX := $(if $(shell clang++ --version 2>$(NULL_DEVICE)),clang++,g++)
endif
ifeq ($(origin CC),default)
    CC := $(subst g++,gcc,$(subst clang++,clang,$(CXX)))
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

# Whether or not to use profile-guided optimization
PGO ?= ON
ifeq ($(BUILD_TYPE),BUILD_DEBUG)
    override PGO := OFF
endif

BUILD_TYPES := BUILD_NATIVE BUILD_VNNI512 BUILD_AVX512 BUILD_AVX2_BMI2 BUILD_AVX2 BUILD_SSE41_POPCNT BUILD_DEBUG
configure = cd $(BUILD_DIR) && cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=$(CMAKE_BUILD_OPTION) -DCMAKE_C_COMPILER=$(CC) -DCMAKE_CXX_COMPILER=$(CXX) -DEVALFILE=$(EVALFILE) $(foreach type,$(BUILD_TYPES),-D$(type)=$(if $(filter $(type),$(BUILD_TYPE)),ON,OFF)) -DDATAGEN=$(DATAGEN) -DPGO_MODE=$(1) ..

# Standard targets
.PHONY: all clean debug x86_64 x86_64_popcnt x86_64_bmi2 native

all: $(BUILD_DIR)
	@echo Building $(EXE) with $(BUILD_TYPE) using $(CXX)...
ifeq ($(PGO),ON)
	@$(call configure,GENERATE)
	@$(MAKE) -C $(BUILD_DIR)
	@echo Generating PGO profile...
	@$(MAKE) -C $(BUILD_DIR) pgo_profile
	@$(call configure,USE)
	@$(MAKE) -C $(BUILD_DIR)
else
	@$(call configure,OFF)
	@$(MAKE) -C $(BUILD_DIR)
endif
	@echo Copying executable...
	@$(MAKE) copy_executable

$(BUILD_DIR):
ifeq ($(detected_OS),Windows)
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
else
	@mkdir -p $(BUILD_DIR)
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