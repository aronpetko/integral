# Default compiler settings
CC=gcc
CXX=g++

# Detect the operating system
ifeq ($(OS),Windows_NT)
    detected_OS := Windows
    EXE ?= integral.exe
else
    detected_OS := $(shell uname -s)
    EXE ?= integral
endif

# Build directory
BUILD_DIR=build

# CMake build option
CMAKE_BUILD_OPTION ?= Release
BUILD_TYPE ?=

# Standard targets
.PHONY: all clean debug build_x86_64 build_x86_64_modern build_x86_64_bmi2

all: $(BUILD_DIR)
	@echo Building $(EXE) with $(BUILD_TYPE)...
	@$(MAKE) -C $(BUILD_DIR) all
ifeq ($(detected_OS),Windows)
	@echo Copying executable...
	@copy $(BUILD_DIR)\integral.exe $(EXE)
else
	@echo Copying executable...
	@cp $(BUILD_DIR)/integral $(EXE)
endif

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
	@if exist $(EXE) del /f /q $(EXE)
else
	@rm -rf $(BUILD_DIR)
	@rm -f $(EXE)
endif

x86_64:
	@echo Building with x86-64 optimizations...
	@$(MAKE) all BUILD_TYPE=BUILD_X86_64

x86_64_modern:
	@echo Building with x86-64 modern optimizations...
	@$(MAKE) all BUILD_TYPE=BUILD_X86_64_MODERN

x86_64_bmi2:
	@echo Building with x86-64 bmi2 optimizations...
	@$(MAKE) all BUILD_TYPE=BUILD_X86_64_BMI2

native:
	@echo Building with native optimizations...
	@$(MAKE) all BUILD_TYPE=BUILD_NATIVE