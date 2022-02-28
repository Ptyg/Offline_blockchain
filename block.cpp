#include "block.h"

#include <iostream>

class Block::display_info() const{
    std::cout << "Block id: " << block_id << '\n';
    std::cout << "Coin number:" << coin_number << '\n';
    std::cout << "Sender: " << sender << '\n';
    std::cout << "Recipient: " << recipient << '\n';
    std::cout << "Block hash: " << block_hash << '\n';
    std::cout << "Created time: " << create_time << '\n';
}