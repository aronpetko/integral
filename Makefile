# Detect OS using Makefile system name
ifeq ($(OS),Windows_NT)
	detected_OS := Windows
else
	detected_OS := $(shell uname -s)
endif

# Define CMake build directory
BUILD_DIR := build

# Default target executed when no arguments are given to make.
default_target: all

.PHONY: default_target all clean distclean

all: $(BUILD_DIR)/Makefile
	@echo Building Integral...
	@$(MAKE) -C $(BUILD_DIR) all

$(BUILD_DIR)/Makefile:
	@echo Creating build directory...
	@mkdir -p $(BUILD_DIR)
	@echo Running CMake...
ifeq ($(detected_OS),Linux)
	@cd $(BUILD_DIR) && cmake -D CMAKE_C_COMPILER=$(CC) -D CMAKE_CXX_COMPILER=$(CXX) ..
endif
ifeq ($(detected_OS),Windows)
	@cd $(BUILD_DIR) && cmake -G "MinGW Makefiles" -D CMAKE_C_COMPILER=$(CC) -D CMAKE_CXX_COMPILER=$(CXX) ..
endif

clean:
	@echo Cleaning...
	@$(MAKE) -C $(BUILD_DIR) clean

distclean:
	@echo Removing build directory...
	@rm -rf $(BUILD_DIR)

# Tell make to run all targets independently
MAKEFLAGS += --no-print-directory