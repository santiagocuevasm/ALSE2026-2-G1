#include "queen_attack.h"
#include <cmath>
#include <stdexcept>

namespace queen_attack {

chess_board::chess_board() : white_({0, 3}), black_({7, 3}) {}

chess_board::chess_board(std::pair<int, int> white, std::pair<int, int> black)
    : white_(white), black_(black) {
    if (white.first < 0 || white.first >= 8 || white.second < 0 || white.second >= 8 ||
        black.first < 0 || black.first >= 8 || black.second < 0 || black.second >= 8) {
        throw std::domain_error("Posicion fuera del tablero");
    }
    if (white == black) {
        throw std::domain_error("Las reinas no pueden estar en la misma casilla");
    }
}

std::pair<int, int> chess_board::white() const { return white_; }
std::pair<int, int> chess_board::black() const { return black_; }

bool chess_board::can_attack() const {
    if (white_.first == black_.first) return true;
    if (white_.second == black_.second) return true;
    if (std::abs(white_.first - black_.first) == std::abs(white_.second - black_.second)) return true;
    return false;
}

}  // namespace queen_attack
