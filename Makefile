CXX = g++
CXXFLAGS = -Wall -std=c++14
CUDA_ROOT_DIR=/usr/local/cuda

BLDD = build
BIND = bin
INCD = include
SRCD = src

NVCC=nvcc
NVCC_FLAGS=
NVCC_LIBS=

CUDA_LIB_DIR= -L$(CUDA_ROOT_DIR)/lib64
CUDA_INC_DIR= -I$(CUDA_ROOT_DIR)/include
CUDA_LINK_LIBS= -lcudart

EXE = physim

SRCS = $(wildcard $(SRCD)/*.cpp)
OBJS = $(SRCS:$(SRCD)/%.cpp=$(BLDD)/%.o)
CUDA_SRCS = $(wildcard $(SRCD)/*.cu)
CUDA_OBJS = $(CUDA_SRCS:$(SRCD)/%.cu=$(BLDD)/%.o)

.PHONY: all
all: $(EXE)

$(BLDD):
	mkdir -p $(BLDD)
	mkdir -p $(BIND)

$(EXE): $(BLDD) $(CUDA_OBJS) $(OBJS) 
	$(CXX) $(CXXFLAGS) -o $(BIND)/$(EXE) $(OBJS) $(CUDA_OBJS) -lSDL2  $(CUDA_LIB_DIR) $(CUDA_LINK_LIBS)

$(BLDD)/%.o : $(SRCD)/%.cu $(INCD)/%.cuh
	$(NVCC) $(NVCC_FLAGS) -I $(INCD) -c $< -o $@ $(NVCC_LIBS)

$(BLDD)/%.o: $(SRCD)/%.cpp | $(BLDD)
	$(CXX) $(CXXFLAGS) -I $(INCD) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(EXE) $(BLDD)/*.o
	rmdir $(BLDD)
	rm -f $(EXE) $(BIND)/*
	rmdir $(BIND)
