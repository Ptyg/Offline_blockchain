#ifndef TRANSACTION
#define TRANSACTION

#ifndef STRING
#define STRING
#include <string>
#endif

class Transaction{
    size_t coin_number;
    std::string sender, recipient;
    std::string block_hash;
    time_t create_time;

    void display_transaction_info() const;
};

#endif TRANSACTION