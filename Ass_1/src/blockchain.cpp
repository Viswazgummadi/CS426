#include "blockchain.h"

Blockchain::Blockchain() {
    Block genesis("0x00", {"Genesis Block"}, 0, "0xffff");
    chain[genesis.hash] = genesis;
    latestHash = genesis.hash;
}

void Blockchain::addBlock(vector<string> transactions) {
    std::lock_guard<std::mutex> lock(mtx);
    Block newBlock(latestHash, transactions);
    chain[newBlock.hash] = newBlock;
    latestHash = newBlock.hash;
}


void Blockchain::tip(const vector<string>& transactions) {
    // Add a new block to the blockchain (tip management)
    std::lock_guard<std::mutex> lock(mtx);
    Block newBlock(latestHash, transactions);
    chain[newBlock.hash] = newBlock;
    latestHash = newBlock.hash;  // Update the latest block's hash
}

void Blockchain::displayBlock(const Block& block) const {
    // Display the details of a single block
    cout << "------ Block ------" << endl;
    cout << "Parent Hash: " << block.parentHash << endl;
    cout << "Nonce: " << block.nonce << endl;
    cout << "Difficulty: " << block.difficulty << endl;
    cout << "Timestamp: " << block.timestamp << endl;
    cout << "Merkle Root: " << block.merkleRoot << endl;
    cout << "Hash: " << block.hash << endl;
}


void Blockchain::displayBlockchainHashes() const {
    for (const auto& pair : chain) {
        cout << "Block Hash: " << pair.first << endl;
    }
}



const Block& Blockchain::getLatestBlock() const {
    // Get the latest block using the latestHash
    return chain.at(latestHash);
}




