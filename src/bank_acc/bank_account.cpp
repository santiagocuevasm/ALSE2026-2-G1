#include "bank_account.h"

namespace Bankaccount {

void Bankaccount::open() {
    std::lock_guard<std::mutex> lock(mtx_);
    if (is_open_) throw std::runtime_error("Ya abierta");
    is_open_ = true;
    balance_ = 0;
}

void Bankaccount::close() {
    std::lock_guard<std::mutex> lock(mtx_);
    if (!is_open_) throw std::runtime_error("Ya cerrada");
    is_open_ = false;
}

void Bankaccount::deposit(int amount) {
    std::lock_guard<std::mutex> lock(mtx_);
    if (!is_open_) throw std::runtime_error("Cuenta cerrada");
    if (amount < 0) throw std::runtime_error("Monto negativo");
    balance_ += amount;
}

void Bankaccount::withdraw(int amount) {
    std::lock_guard<std::mutex> lock(mtx_);
    if (!is_open_) throw std::runtime_error("Cuenta cerrada");
    if (amount < 0 || amount > balance_) throw std::runtime_error("Monto inválido");
    balance_ -= amount;
}

int Bankaccount::balance() const {
    std::lock_guard<std::mutex> lock(mtx_);
    if (!is_open_) throw std::runtime_error("Cuenta cerrada");
    return balance_;
}

} // namespace Bankaccount
