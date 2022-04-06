#include "transactionPool.hpp"
#include "transaction.hpp"
#include "block.hpp"
#include "blockchain.hpp"

#include <iostream>
#include <string>
#include <memory>
#include <ctime>
#include <stdexcept>


void add_transaction(const TransactionPool* pool){
    int coinNum;
    std::string sender, recipient;
    time_t createdTime;

    auto check_input = [](const bool& check){
        if (!check){ 
            throw std::invalid_argument("Invalid input"); 
        }
    };
    
    try{
        std::cout << "Number of coins: "; std::cin >> coinNum;
        check_input(std::cin.good());

        std::cout << "Sender: "; std::cin >> sender;
        check_input(std::cin.good());

        std::cout << "Recipient: "; std::cin >> recipient;
        check_input(std::cin.good());

    }
    catch(const std::invalid_argument& e){
        std::cout << "Error: " << e.what() << std::endl;
        std::cin.clear();
        std::cin.ignore();
        return;
    }
    
    Transaction newTransaction(std::move(coinNum), std::move(sender), std::move(recipient), std::move(time(&createdTime)));
    pool->addTransaction(std::move(newTransaction));
}

int main()
{
    const BlockChain* chain = BlockChain::get_instance(); 
    const TransactionPool* pool = TransactionPool::get_instance();
    char ch;
    int numberOfBlocks;

    while (ch != 'E'){
        std::cout << "\nWhat do you want to do?\n\n";
        std::cout << "01. Add transaction\n";
        std::cout << "02. Show blocks\n";
        std::cout << "03. Show transaction pool\n";
        std::cout << "04. Show extra info from blocks about transactions\n";
        std::cout << "E. Exit\n";
        std::cout << "Choice: "; std::cin >> ch;

        switch(ch){
            case '1': add_transaction(pool); break;

            case '2': 
                std::cout << "\nNumber of blocks: "; std::cin >> numberOfBlocks;
                BlockChain::show_blocks(numberOfBlocks); 
            break;

            case '3': TransactionPool::showTransactionsInPool(); break;
            
            case '4':
                std::cout << "\nNumber of blocks: "; std::cin >> numberOfBlocks;
                BlockChain::show_blocks(numberOfBlocks, true); 
            break;
            
            case 'E': break;
            default: std::cout << '\n'; break;
        }
    }
    delete chain;
    delete pool;
    return 0;
}
