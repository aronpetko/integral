# default compiler settings
CC=gcc
CXX=g++

# output binary name, default is 'integral'
EXE ?= integral

# build directory
BUILD_DIR=build

# standard targets
.PHONY: all clean

all: $(BUILD_DIR)
	@echo "Building $(EXE)..."
	@$(MAKE) -C $(BUILD_DIR) all
	@cp $(BUILD_DIR)/integral $(EXE)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)
	@cd $(BUILD_DIR) && cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=$(CC) -DCMAKE_CXX_COMPILER=$(CXX) ..

clean:
	@rm -rf $(BUILD_DIR) $(EXE)