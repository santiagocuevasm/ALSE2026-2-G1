#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <mutex>
#include <stdexcept>

namespace Bankaccount {

class Bankaccount {
private:
    int balance_{0};
    bool is_open_{false};
    mutable std::mutex mtx_;

public:
    Bankaccount() = default;
    void open();
    void close();
    void deposit(int amount);
    void withdraw(int amount);
    int balance() const;
};

} // namespace Bankaccount

#endif
