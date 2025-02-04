CXX = g++
CXXFLAGS = -Wall -std=c++11 -Iinc
LDFLAGS = -lssl -lcrypto

SRC = src/block.cpp src/blockchain.cpp src/utils.cpp src/main.cpp
OBJ = $(SRC:.cpp=.o)
BIN = bin/blockchain

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(BIN) $(OBJ) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BIN)
