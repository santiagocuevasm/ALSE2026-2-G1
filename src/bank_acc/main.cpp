#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include "bank_account.h"

int main() {
    Bankaccount::Bankaccount account;
    account.open();
    account.deposit(1000);

    auto deposit_task = [&account]() {
        for (int i = 0; i < 100; ++i) {
            account.deposit(10);
        }
    };

    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(deposit_task);
    }
    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Saldo final esperado 2000, obtenido: " << account.balance() << std::endl;
    return 0;
}
