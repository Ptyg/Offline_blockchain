#include "transaction.h"

#include <iostream>

void Transaction::display_transaction_info() const{
    std::cout << "Sender: " << sender << '\n';
    std::cout << "Recipient: " << recipient << '\n';
    std::cout << "Coin number: " << coin_number << '\n';
    std::cout << "Block hash: " << block_hash << '\n';
    std::cout << "Create time: " << create_time << '\n';
}