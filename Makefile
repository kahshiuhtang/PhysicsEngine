CXX = g++
CXXFLAGS = -Wall -std=c++11
CUDA_ROOT_DIR=/usr/local/cuda

BUILD_DIR = build
BIN_DIR = bin
INC_DIR = include
SRC_DIR = src

NVCC=nvcc
NVCC_FLAGS=
NVCC_LIBS=

CUDA_LIB_DIR= -L$(CUDA_ROOT_DIR)/lib64
CUDA_INC_DIR= -I$(CUDA_ROOT_DIR)/include
CUDA_LINK_LIBS= -lcudart

EXE = physim

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
CUDA_SRCS = $(wildcard $(SRC_DIR)/*.cu)
CUDA_OBJS = $(CUDA_SRCS:$(SRC_DIR)/%.cu=$(BUILD_DIR)/%.o)

.PHONY: all
all: $(EXE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BIN_DIR)

$(EXE): $(BUILD_DIR) $(CUDA_OBJS) $(OBJS) 
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/$(EXE) $(OBJS) $(CUDA_OBJS) -lsfml-graphics -lsfml-window -lsfml-system $(CUDA_LIB_DIR) $(CUDA_LINK_LIBS)

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.cu $(INC_DIR)/%.cuh
	$(NVCC) $(NVCC_FLAGS) -I $(INC_DIR) -c $< -o $@ $(NVCC_LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I $(INC_DIR) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(EXE) $(BUILD_DIR)/*.o
	rmdir $(BUILD_DIR)
	rm -f $(EXE) $(BIN_DIR)/*
	rmdir $(BIN_DIR)
