CXX = g++
CXXFLAGS = -Wall -std=c++11

BUILD_DIR = build
BIN_DIR = bin
INCL_DIR = include
SRC_DIR = src


TARGET = physim

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

.PHONY: all
all: $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BIN_DIR)

$(TARGET): $(BUILD_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/$(TARGET) $(OBJS) -lsfml-graphics -lsfml-window -lsfml-system

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I $(INCL_DIR) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(TARGET) $(BUILD_DIR)/*.o
	rmdir $(BUILD_DIR)
	rm -f $(TARGET) $(BIN_DIR)/*
	rmdir $(BIN_DIR)
