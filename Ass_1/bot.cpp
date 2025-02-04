/* Organized Blockchain Implementation */

// Directory Structure:
// - inc/ -> Header files
// - src/ -> Source files
// - obj/ -> Compiled object files
// - bin/ -> Executable
// - Makefile for easy compilation

// Required Libraries
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <openssl/sha.h>
#include <thread>
#include <map>

using namespace std;

// Hash function utility
string sha256(const string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)data.c_str(), data.size(), hash);
    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}

// Block Class
class Block {
public:
    string parentHash;
    int nonce;
    string difficulty;
    time_t timestamp;
    string merkleRoot;
    vector<string> transactions;
    string hash;

    Block(string prevHash, vector<string> txs, int _nonce = 0, string _difficulty = "0000")
        : parentHash(prevHash), transactions(txs), nonce(_nonce), difficulty(_difficulty) {
        timestamp = time(nullptr);
        merkleRoot = calculateMerkleRoot(txs);
        hash = calculateHash();
    }

    string calculateHash() const {
        stringstream ss;
        ss << parentHash << merkleRoot << nonce << timestamp;
        return sha256(ss.str());
    }

    static string calculateMerkleRoot(const vector<string>& txs) {
        if (txs.empty()) return "";
        string merkle = "";
        for (const string& tx : txs) merkle += sha256(tx);
        return sha256(merkle);
    }
};

// Blockchain Class
class Blockchain {
private:
    map<string, Block> chain;
    string latestHash;

public:
    Blockchain() {
        Block genesis("0x00", {"Genesis Block"}, 0, "0xffff");
        chain[genesis.hash] = genesis;
        latestHash = genesis.hash;
    }

    void addBlock(vector<string> transactions) {
        Block newBlock(latestHash, transactions);
        chain[newBlock.hash] = newBlock;
        latestHash = newBlock.hash;
    }

    void displayBlockchainHashes() const {
        for (const auto& pair : chain) {
            cout << "Block Hash: " << pair.first << endl;
        }
    }
};

// Threaded Mining Function
void miner(Blockchain& bc, int numBlocks) {
    for (int i = 0; i < numBlocks; i++) {
        vector<string> txs = {"TX1", "TX2"};
        bc.addBlock(txs);
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

// Main Function
int main() {
    Blockchain bc;
    vector<thread> miners;
    for (int i = 0; i < 5; i++) miners.emplace_back(miner, ref(bc), 10);
    for (auto& t : miners) t.join();

    bc.displayBlockchainHashes();
    return 0;
}
