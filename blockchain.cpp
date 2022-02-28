#include "blockchain.h"

#include <iostream>

class BlockChain::showBlocks(int amount = 1, bool show_all = false){
    for (size_t i = blockchain.size() - 1; i >= amount || i >= 0; i--)
    {
        std::cout << "\n###########################################\n"
        blockchain[i].display_info();
        std::cout << "\n###########################################\n"
    }
}