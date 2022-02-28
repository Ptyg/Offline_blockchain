#ifndef STRING
#define STRING
#include <string>
#endif STRING

#ifndef BLOCK
#define BLOCK
class Block{
    int block_id;
    int coin_number;
    std::string sender, recipient;
    std::string block_hash;
    time_t create_time;
public:
    void display_info() const;
};
#endif BLOCK