#ifndef ROBOT_SIMULATOR_H
#define ROBOT_SIMULATOR_H

#include <string>
#include <utility>

namespace robot_simulator {

enum class Bearing {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

class Robot {
private:
    std::pair<int, int> position_;
    Bearing bearing_;

public:
    Robot();
    Robot(std::pair<int, int> position, Bearing bearing);

    std::pair<int, int> get_position() const;
    Bearing get_bearing() const;

    void turn_right();
    void turn_left();
    void advance();
    void execute_sequence(const std::string& sequence);
};

}

#endif
