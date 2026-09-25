#ifndef QUEEN_ATTACK_H
#define QUEEN_ATTACK_H

#include <utility>

namespace queen_attack {

class chess_board {
private:
    std::pair<int, int> white_;
    std::pair<int, int> black_;

public:
    chess_board();
    chess_board(std::pair<int, int> white, std::pair<int, int> black);

    std::pair<int, int> white() const;
    std::pair<int, int> black() const;

    bool can_attack() const;
};

}

#endif
