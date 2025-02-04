#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class Block {
public:
    string parentHash;
    int nonce;
    string difficulty;
    time_t timestamp;
    string merkleRoot;
    vector<string> transactions;
    string hash;

    // Default Constructor
    Block() : parentHash(""), nonce(0), difficulty("0000"), timestamp(0), merkleRoot(""), hash("") {}

    // Parameterized Constructor
    Block(string prevHash, vector<string> txs, int _nonce = 0, string _difficulty = "0000");

    string calculateHash() const;
    static string calculateMerkleRoot(const vector<string>& txs);
};

#endif // BLOCK_H
