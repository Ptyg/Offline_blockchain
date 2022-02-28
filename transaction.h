#ifndef STRING
#define STRING
#include <string>
#endif

#ifndef TRANSACTION
#define TRANSACTION

struct Transaction{
    size_t coin_number;
    std::string sender, recipient;
    std::string block_hash;
    time_t create_time;
};

#endif TRANSACTION