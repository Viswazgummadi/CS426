#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "block.h"
#include <map>
#include <mutex>
class Blockchain {
private:
    map<string, Block> chain;
    string latestHash;
    mutable std::mutex mtx;

public:
    Blockchain();
    void addBlock(vector<string> transactions);
    void tip(const vector<string>& transactions);  // Adds a new block (tip management
    void displayBlock(const Block& block) const;
    void displayBlockchainHashes() const;
    const Block& getLatestBlock() const;



};

#endif // BLOCKCHAIN_H
