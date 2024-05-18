# Detect the operating system
ifeq ($(OS),Windows_NT)
    DETECTED_OS := Windows
else
    DETECTED_OS := $(shell uname -s)
endif

# Default compiler settings
CC=gcc
CXX=g++

# Output binary name
ifeq ($(DETECTED_OS),Windows)
    EXE ?= integral.exe
else
    EXE ?= integral
endif

# Build directory
BUILD_DIR=build

# Standard targets
.PHONY: all clean debug

all: $(BUILD_DIR)/Makefile
	@echo Building $(EXE)...
	@$(MAKE) -C $(BUILD_DIR) all
	@echo Copying executable...
ifeq ($(DETECTED_OS),Windows)
	@copy $(BUILD_DIR)\$(EXE) $(EXE)
else
	@cp $(BUILD_DIR)/$(EXE) $(EXE)
endif

$(BUILD_DIR)/Makefile: $(BUILD_DIR)
	@echo "Configuring CMake..."
ifeq ($(DETECTED_OS),Windows)
	@cmd /c configure_cmake.bat
else
	@sh configure_cmake.sh
endif

$(BUILD_DIR):
ifeq ($(DETECTED_OS),Windows)
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
else
	@mkdir -p $(BUILD_DIR)
endif

clean:
ifeq ($(DETECTED_OS),Windows)
	@if exist $(BUILD_DIR) rmdir /s /q $(BUILD_DIR)
	@if exist $(EXE) del /f /q $(EXE)
else
	@rm -rf $(BUILD_DIR)
	@rm -f $(EXE)
endif

debug:
	@echo CC=$(CC)
	@echo CXX=$(CXX)
	@echo DETECTED_OS=$(DETECTED_OS)
	@echo BUILD_DIR=$(BUILD_DIR)
	@echo EXE=$(EXE)