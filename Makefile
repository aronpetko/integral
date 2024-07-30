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

# Executable name (can be overridden from command line)
EXE ?= integral

# Standard targets
.PHONY: all clean debug x86_64 x86_64_popcnt x86_64_bmi2 native

all: $(BUILD_DIR)
	@echo Building $(EXE) with $(BUILD_TYPE)...
ifeq ($(detected_OS),Windows)
	@$(MAKE) -C $(BUILD_DIR) all > NUL 2>&1
else
	@$(MAKE) -C $(BUILD_DIR) all > /dev/null 2>&1
endif
	@echo Copying executable...
	@$(MAKE) copy_executable

$(BUILD_DIR):
ifeq ($(detected_OS),Windows)
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
else
	@mkdir -p $(BUILD_DIR)
endif
	@echo Configuring CMake with BUILD_TYPE=$(BUILD_TYPE)...
	@cd $(BUILD_DIR) && cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=$(CMAKE_BUILD_OPTION) -DCMAKE_C_COMPILER=$(CC) -DCMAKE_CXX_COMPILER=$(CXX) -D$(BUILD_TYPE)=ON ..

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
	@echo Building with debug...
	@$(MAKE) all BUILD_TYPE=BUILD_DEBUG

x86_64_popcnt:
	@echo Building with x86-64 optimizations...
	@$(MAKE) all BUILD_TYPE=BUILD_X86_64_POPCNT

x86_64_modern:
	@echo Building with x86-64 modern optimizations...
	@$(MAKE) all BUILD_TYPE=BUILD_X86_64_MODERN

x86_64_bmi2:
	@echo Building with x86-64 bmi2 optimizations...
	@$(MAKE) all BUILD_TYPE=BUILD_X86_64_BMI2

native:
	@echo Building with native optimizations...
	@$(MAKE) all BUILD_TYPE=BUILD_NATIVE