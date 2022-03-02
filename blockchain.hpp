#ifndef VECTOR
#define VECTOR
#include <vector>
#endif VECTOR

#ifndef BLOCKCHAIN
#define BLOCKCHAIN

class BlockChain{
    std::vector<Block> blockchain;
public:
    void showBlocks(int amount = 1, bool show_all = false) const;
    void showBlockInfo(int id) const;
};

#endif BLOCKCHAIN