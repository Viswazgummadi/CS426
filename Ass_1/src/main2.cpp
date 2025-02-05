#include "blockchain.h"
#include <thread>
#include <chrono>
#include <vector>


void miner(Blockchain& bc, int numBlocks) {
    for (int i = 0; i < numBlocks; i++) {
        vector<string> txs = {"TX" + std::to_string(i+1), "TX" + std::to_string(i+2)};
        bc.addBlock(txs);
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

int main() {



    Blockchain bc;

    vector<thread> miners;
    for (int i = 0; i < 5; i++) {
        miners.emplace_back(miner, std::ref(bc), 10);
    }
    for (auto& t : miners) {
        t.join();
    }


    // Display the current tip of the blockchain (the latest block)


    Block tip = bc.getLatestBlock();
    cout << "\nCurrent Tip of the Blockchain (Latest Block):" << endl;
    bc.displayBlock(tip);  // Display block details (parent hash, nonce, difficulty, etc.)



    bc.displayBlockchainHashes(0);  // Display the hashes of all blocks in the chain
    bc.displayBlockchainHashes(1);


    return 0;
}

