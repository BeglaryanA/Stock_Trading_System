# Makefile for Stock Trading System

# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -Werror

# Directories
SRC_DIR := src
HELPER_DIR := helper
OBJ_DIR := obj
BIN_DIR := bin
INCLUDE_DIR := include

# Source files
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
HELPER_FILES := $(wildcard $(HELPER_DIR)/*.cpp)
MAIN_FILE := main.cpp  # Add main.cpp as a separate source file
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))
OBJ_FILES += $(patsubst $(HELPER_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(HELPER_FILES))
OBJ_FILES += $(patsubst ./%.cpp, $(OBJ_DIR)/%.o, $(MAIN_FILE))  # Include main.cpp

# Target binary
TARGET := $(BIN_DIR)/stock_trading_system

# Main target
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -o $@ $^

# Build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

$(OBJ_DIR)/%.o: $(HELPER_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

$(OBJ_DIR)/%.o: %.cpp  # Compile main.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

# Create necessary directories
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

.PHONY: clean

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)