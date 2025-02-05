#include "blockchain.h"

Blockchain::Blockchain() {
    Block genesis("0x00", {"Genesis Block"}, 1000, "0000000000000000000000000000000000000000");
    chain[genesis.hash] = genesis;
    blockOrder.push_back(genesis.hash);
    latestHash = genesis.hash;

    cout << "Genesis Block created with hash: " << genesis.hash << endl;
}

void Blockchain::addBlock(const vector<string>& transactions) {
    std::lock_guard<std::mutex> lock(mtx);

    int newNonce = (getBlockchainHeight() + 1) * 1000;  // Increment nonce per block

    // create new block
    Block newBlock(latestHash, transactions, newNonce);

    // store them in map (chain) and vector (blockOrder)

    chain[newBlock.hash] = newBlock;
    blockOrder.push_back(newBlock.hash);

    // set latest hash to it
    latestHash = newBlock.hash;

    // print the block details
    displayBlock(newBlock);
}


void Blockchain::tip(const vector<string>& transactions) {
    // Add a new block to the blockchain (tip management)
    std::lock_guard<std::mutex> lock(mtx);
    Block newBlock(latestHash, transactions);
    chain[newBlock.hash] = newBlock;
    latestHash = newBlock.hash;  // Update the latest block's hash
}

// tip and addblock are same one prints and other doesnt.


void Blockchain::displayBlock(const Block& block) const {
    // Display the details of a single block
//    cout << "------ Block ------" << endl;
    cout << "\n------ New Block ------" << endl;
    cout << "Parent Hash: " << block.parentHash << endl;
    cout << "Nonce: " << block.nonce << endl;
    cout << "Difficulty: " << block.difficulty << endl;
    cout << "Timestamp: " << block.timestamp << endl;
    cout << "Merkle Root: " << block.merkleRoot << endl;
    cout << "Hash: " << block.hash << endl;


    // Print block details after adding
    cout << "Current Blockchain Height: " << getBlockchainHeight() << endl;
    cout << "-----------------------------" << endl;
}



void Blockchain::displayBlockchainHashes(bool rev) const {
//    for (const auto& pair : chain) {
//        cout << "Block Hash: " << pair.first << endl;
//    }
    if (rev) {

        cout << "Blockchain from Tip to Genesis: " << endl;
        // Print in reverse order (Tip to Genesis)
        for (auto it = blockOrder.rbegin(); it != blockOrder.rend(); ++it) {
            cout << "Block Hash: " << *it << endl;

        }
    }
    else
    {
        cout << "Blockchain from Genesis to Tip: " << endl;
        // Print in normal order (Genesis to Tip)
        for (const auto& it : blockOrder) {
            cout << "Block Hash: " << it << endl;
        }
    }
}


const Block& Blockchain::getLatestBlock() const {
    std::lock_guard<std::mutex> lock(mtx);  // Ensure thread safety
    if (chain.find(latestHash) == chain.end()) {
        throw std::runtime_error("Error: Latest block hash not found in blockchain.");
    }
    else if (chain.empty())
    {
        throw std::runtime_error("empty chain");
    }
    return chain.at(latestHash);
}


int Blockchain::getBlockchainHeight() const {
    return blockOrder.size() - 1;  // Excluding genesis block
}
