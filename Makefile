# Default compiler settings
CC ?= gcc
CXX ?= g++

# Detect the operating system
ifeq ($(OS),Windows_NT)
    detected_OS := Windows
    EXE ?= integral.exe
else
    detected_OS := $(shell uname -s)
    EXE ?= integral
endif

# Output binary name, default is 'integral.exe' or 'integral' based on OS

# Build directory
BUILD_DIR=build

# Standard targets
.PHONY: all clean debug

all: $(BUILD_DIR)
	@echo Building $(EXE)...
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
	@echo Configuring CMake...
	@cd $(BUILD_DIR) && cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=$(CC) -DCMAKE_CXX_COMPILER=$(CXX) ..

clean:
ifeq ($(detected_OS),Windows)
	@if exist $(BUILD_DIR) rmdir /s /q $(BUILD_DIR)
	@if exist $(EXE) del /f /q $(EXE)
else
	@rm -rf $(BUILD_DIR)
	@rm -f $(EXE)
endif

debug:
	@echo CC=$(CC)