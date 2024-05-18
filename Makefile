# Detect OS using Makefile system name
ifeq ($(OS),Windows_NT)
	detected_OS := Windows
	CP_CMD := copy /Y
	DEL_CMD := del /F /Q
	MKDIR_CMD := mkdir
	RMDIR_CMD := rmdir /s /q
	PATH_SEP := \\
else
	detected_OS := $(shell uname -s)
	CP_CMD := cp -f
	DEL_CMD := rm -f
	MKDIR_CMD := mkdir -p
	RMDIR_CMD := rm -rf
	PATH_SEP := /
endif

# Define CMake build directory
BUILD_DIR := build

# Default compiler settings
CC = gcc
CXX ?= g++

# Output binary name, default is 'Integral'
EXE ?= integral

# Default target executed when no arguments are given to make.
default_target: all

.PHONY: default_target all clean distclean debug

all: $(BUILD_DIR)/Makefile
	@echo Building $(EXE)...
	@$(MAKE) -C $(BUILD_DIR) all
	@echo Copying executable...
	@$(CP_CMD) $(BUILD_DIR)$(PATH_SEP)$(EXE)$(EXE_EXT) .

$(BUILD_DIR)/Makefile:
	@echo Creating build directory...
	@$(MKDIR_CMD) $(BUILD_DIR)
	@echo Running CMake...
ifeq ($(detected_OS),Linux)
	@cd $(BUILD_DIR) && cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=$(CC) -DCMAKE_CXX_COMPILER=$(CXX) ..
endif
ifeq ($(detected_OS),Windows)
	@cd $(BUILD_DIR) && cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=$(CC) -DCMAKE_CXX_COMPILER=$(CXX) ..
endif

clean:
	@echo Cleaning...
	@$(MAKE) -C $(BUILD_DIR) clean
	@$(DEL_CMD) $(EXE)$(EXE_EXT)

distclean:
	@echo Removing build directory...
	@$(RMDIR_CMD) $(BUILD_DIR)

debug:
	@echo CC=$(CC)

# Tell make to run all targets independently
MAKEFLAGS += --no-print-directory

# Extension for executables
EXE_EXT ?= $(if $(findstring Windows,$(detected_OS)),.exe,)