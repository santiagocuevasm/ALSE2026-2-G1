cmake_minimum_required(VERSION 3.10)
project(ProyectoCorte2CXX CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)

# Ejercicio 1: Gestor de Autenticación
add_executable(app_auth_manager
    src/auth_manager/main.cpp
)

# Ejercicio 2: Seguimiento de Exámenes
add_executable(app_exam_tracker
    src/exam_tracker/main.cpp
)

# Ejercicio 3: Crypto Square
add_executable(app_crypto_square
    src/crypto_sq/main.cpp
    src/crypto_sq/crypto_square.cpp
)

# Ejercicio 4: Cuenta Bancaria
add_executable(app_bank_account
    src/bank_acc/main.cpp
    src/bank_acc/bank_account.cpp
)
target_link_libraries(app_bank_account PRIVATE Threads::Threads)
