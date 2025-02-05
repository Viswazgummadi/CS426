#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "block.h"
#include <map>
#include <mutex>
#include <vector>


class Blockchain {
private:
    map<string, Block> chain;  //so we can lookup easily
    vector<string> blockOrder;  // we can maintain the order of blocks
    string latestHash; // the latest element in the block order
    mutable std::mutex mtx; // lock for no overwriting (not needed as of now)

public:
    Blockchain(); // add a genesis block to it when initializing (done in .cpp)
    void addBlock(const vector<string>& transactions);
    void tip(const vector<string>& transactions);  // Adds a new block (tip management
    void displayBlock(const Block& block) const;
    void displayBlockchainHashes(bool rev = true) const;



    // some helper functions
    const Block& getLatestBlock() const;
    int getBlockchainHeight() const;



};

#endif // BLOCKCHAIN_H
