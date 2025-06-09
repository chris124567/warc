# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++20 -Ofast -march=native -Wall -Wextra -I./src -I./tests

# Google Test flags (assuming installed globally)
GTEST_LIBS := -lgtest -lgtest_main -pthread

# Directories
SRC_DIR := src
TEST_DIR := tests
BUILD_DIR := build

# Files
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
SRC_NO_MAIN := $(filter-out $(SRC_DIR)/main.cpp, $(SRC_FILES))
TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp)

# Output binaries
MAIN_BIN := $(BUILD_DIR)/main
TEST_BIN := $(BUILD_DIR)/test

.PHONY: all main test clean

all: main

main: $(MAIN_BIN)

$(MAIN_BIN): $(SRC_FILES) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

test: $(TEST_BIN)

$(TEST_BIN): $(SRC_NO_MAIN) $(TEST_FILES) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_LIBS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
