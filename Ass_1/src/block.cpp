#include "block.h"
#include "utils.h"

Block::Block(string prevHash, vector<string> txs, int _nonce, string _difficulty)
    : parentHash(prevHash), nonce(_nonce), difficulty(_difficulty), timestamp(time(nullptr)),
      merkleRoot(calculateMerkleRoot(txs)), transactions(txs), hash(calculateHash()) {}

string Block::calculateHash() const {
    stringstream ss;
    ss << parentHash << merkleRoot << nonce << timestamp;
    return sha256(ss.str());
}

string Block::calculateMerkleRoot(const vector<string>& txs) {
    if (txs.empty()) return "";
    string merkle = "";
    for (const string& tx : txs) merkle += sha256(tx);
    return sha256(merkle);
}
