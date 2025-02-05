#include "blockchain.h"
#include <thread>
#include <chrono>
#include <vector>


int main() {



    Blockchain bc;


    for (int i = 0; i < 50; i++) {
        vector<string> txs = {"TX" + std::to_string(i+1)};
        bc.addBlock(txs);
    }

    // Display the current tip of the blockchain (the latest block)


    Block tip = bc.getLatestBlock();
    cout << "\nCurrent Tip of the Blockchain (Latest Block):" << endl;
    bc.displayBlock(tip);  // Display block details (parent hash, nonce, difficulty, etc.)



    bc.displayBlockchainHashes(0);  // Display the hashes of all blocks in the chain
    bc.displayBlockchainHashes(1);


    return 0;
}

