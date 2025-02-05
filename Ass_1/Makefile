CXX = g++
CXXFLAGS = -Wall -std=c++11 -Iinc
LDFLAGS = -lssl -lcrypto
BIN_DIR = bin
OUTPUT_DIR = outputs

SRC_COMMON = src/block.cpp src/blockchain.cpp src/utils.cpp
SRC_PART1 = $(SRC_COMMON) src/main1.cpp
SRC_PART2 = $(SRC_COMMON) src/main2.cpp
OBJ_PART1 = $(SRC_PART1:.cpp=.o)
OBJ_PART2 = $(SRC_PART2:.cpp=.o)
BIN = bin/blockchain

$(shell mkdir -p $(BIN_DIR))
$(shell mkdir -p $(OUTPUT_DIR))

# Default target
all: help

# Display available commands
help:
	@echo "Available make commands:"
	@echo "  make part1     - Compile and build Part 1"
	@echo "  make part2     - Compile and build Part 2"
	@echo "  make run_part1 - Run Part 1 executable and save output to outputs/output_1"
	@echo "  make run_part2 - Run Part 2 executable and save output to outputs/output_2"
	@echo "  make clean     - Remove compiled files"

# Part 1: Sequential block addition
part1: CXXFLAGS += -DPART1
part1: $(BIN)_part1

# Part 2: Multi-threaded block mining
part2: CXXFLAGS += -DPART2
part2: $(BIN)_part2

$(BIN)_part1: $(OBJ_PART1)
	$(CXX) $(CXXFLAGS) -o $(BIN)_part1 $(OBJ_PART1) $(LDFLAGS)

$(BIN)_part2: $(OBJ_PART2)
	$(CXX) $(CXXFLAGS) -o $(BIN)_part2 $(OBJ_PART2) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run_part1: $(BIN)_part1
	./bin/blockchain_part1 > outputs/output_1

run_part2: $(BIN)_part2
	./bin/blockchain_part2 > outputs/output_2

clean:
	rm -f $(OBJ_PART1) $(OBJ_PART2) $(BIN)_part1 $(BIN)_part2
	rm -rf $(OUTPUT_DIR)
