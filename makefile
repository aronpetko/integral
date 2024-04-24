# Default compiler settings
CC=gcc
CXX=g++

# Output binary name, default is 'integral.exe'
EXE ?= integral.exe

# Build directory
BUILD_DIR=build

# Standard targets
.PHONY: all clean debug

all: $(BUILD_DIR)
	@echo Building $(EXE)...
	@$(MAKE) -C $(BUILD_DIR) all
	@echo Copying executable...
	@copy $(BUILD_DIR)\integral.exe $(EXE)

$(BUILD_DIR):
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
	@echo Configuring CMake...
	@cd $(BUILD_DIR) && cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=$(CC) -DCMAKE_CXX_COMPILER=$(CXX) ..

clean:
	@if exist $(BUILD_DIR) rmdir /s /q $(BUILD_DIR)
	@if exist $(EXE) del /f /q $(EXE)

debug:
	@echo CC=$(CC)
