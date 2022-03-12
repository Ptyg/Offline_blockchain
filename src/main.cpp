#include "transactionPool.hpp"
#include "transaction.hpp"
#include "block.hpp"
#include "blockchain.hpp"

#include <iostream>
#include <string>
#include <memory>
#include <ctime>

void add_transaction(TransactionPool& pool){
    size_t coinNum;
    std::string sender, recipient;
    time_t createdTime;

    std::cout << "Number of coins: "; std::cin >> coinNum;
    std::cout << "Sender: "; std::cin >> sender;
    std::cout << "Recipient: "; std::cin >> recipient;

    Transaction newTransaction(std::move(coinNum), std::move(sender), std::move(recipient), std::move(time(&createdTime)));
    pool.addTransaction(std::move(newTransaction));
}

int main()
{
    BlockChain* chain = BlockChain::get_instance();
    TransactionPool* pool = TransactionPool::get_instance();
    char ch;

    while (ch != 'E'){
        std::cout << "\nWhat do you want to do?\n\n";
        std::cout << "01. Add transaction\n";
        std::cout << "02. Show blocks\n";
        std::cout << "03. Show trans pool\n";
        std::cout << "E. Exit\n";
        std::cout << "Choice: "; std::cin >> ch;

        switch(ch){
            case '1': add_transaction(pool); break;
            case '2': 
                int numberOfBlocks;
                std::cout << "\nNumber o blocks: "; std::cin >> numberOfBlocks;
                BlockChain::show_blocks(numberOfBlocks); 
            break;
            case '3': TransactionPool::showTransactionsInPool(); break;
            case 'E': break;
            default: std::cout << '\a'; break;
        }
    }
    return 0;
}

// проверить на тестах