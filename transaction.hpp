#ifndef TRANSACTION
#define TRANSACTION

#ifndef STRING
#define STRING
#include <string>
#endif

class Transaction{
    size_t coin_number;
    std::string sender, recipient;
    time_t create_time;
public:
    void display_transaction_info() const;
    const size_t& get_coin_number() const;
    const std::string& get_sender() const;
    const std::string& get_recipient() const;
    const time_t& get_create_time() const;
    void add_in_transaction_pool();
};

#endif TRANSACTION