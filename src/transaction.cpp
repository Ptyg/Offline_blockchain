#include "transaction.hpp"
#include <iostream>

Transaction::Transaction(size_t&& coin_number, std::string&& sender, std::string&& recipient, time_t&& create_time) 
    : coin_number(coin_number), sender(sender), recipient(recipient), create_time(create_time) {} 


void Transaction::display_transaction_info() const{
    std::cout << "Sender: " << sender << '\n';
    std::cout << "Recipient: " << recipient << '\n';
    std::cout << "Coin number: " << coin_number << '\n';
    std::cout << "Create time: " << create_time << '\n';
}

const size_t& Transaction::get_coin_number() const{ return coin_number; }
const std::string& Transaction::get_sender() const{ return sender; }
const std::string& Transaction::get_recipient() const{ return recipient; }
const time_t& Transaction::get_create_time() const{ return create_time; }