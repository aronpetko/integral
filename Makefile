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

all: $(BUILD_DIR)
	@echo Building $(EXE)...
	@$(MAKE) -C $(BUILD_DIR) all
	@echo Copying executable...
ifeq ($(DETECTED_OS),Windows)
	@copy $(BUILD_DIR)\$(EXE) $(EXE)
else
	@cp $(BUILD_DIR)/$(EXE) $(EXE)
endif

$(BUILD_DIR):
ifeq ($(DETECTED_OS),Windows)
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
else
	@mkdir -p $(BUILD_DIR)
endif
	@echo Configuring CMake...
	@cd $(BUILD_DIR) && cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=$(CC) -DCMAKE_CXX_COMPILER=$(CXX) ..

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
	@echo DETECTED_OS=$(DETECTED_OS)