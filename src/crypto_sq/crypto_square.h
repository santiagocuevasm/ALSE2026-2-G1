#ifndef CRYPTO_SQUARE_H
#define CRYPTO_SQUARE_H

#include <string>

namespace crypto_square {
    class cipher {
    private:
        std::string plain_text_;
    public:
        explicit cipher(const std::string& text);
        std::string normalized_cipher_text() const;
    };
}

#endif
