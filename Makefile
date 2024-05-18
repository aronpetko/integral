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
	if exist CMakeLists.txt (
		echo "CMakeLists.txt found"
	) else (
		echo "Error: CMakeLists.txt not found"
		exit 1
	)
else
	@if [ -f CMakeLists.txt ]; then \
		echo "CMakeLists.txt found"; \
	else \
		echo "Error: CMakeLists.txt not found"; \
		exit 1; \
	fi
endif
	@cd $(BUILD_DIR) && cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=$(CC) -DCMAKE_CXX_COMPILER=$(CXX) ..
ifeq ($(DETECTED_OS),Windows)
	if not exist $(BUILD_DIR)/Makefile (
		echo "Error: Makefile not generated in $(BUILD_DIR)"
		exit 1
	)
else
	@if [ ! -f $(BUILD_DIR)/Makefile ]; then \
		echo "Error: Makefile not generated in $(BUILD_DIR)"; \
		exit 1; \
	fi
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