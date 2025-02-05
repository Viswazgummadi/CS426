CXX = g++
CXXFLAGS = -Wall -std=c++11 -Iinc
LDFLAGS = -lssl -lcrypto

SRC = src/block.cpp src/blockchain.cpp src/utils.cpp src/main.cpp
OBJ = $(SRC:.cpp=.o)
BIN = bin/blockchain

# Default target
all: part1

# Part 1: Sequential block addition
part1: CXXFLAGS += -DPART1
part1: $(BIN)

# Part 2: Multi-threaded block mining
part2: CXXFLAGS += -DPART2
part2: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(BIN) $(OBJ) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
run: $(BIN)
	./bin/blockchain
clean:
	rm -f $(OBJ) $(BIN)
