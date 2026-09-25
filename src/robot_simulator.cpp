#include "robot_simulator.h"

namespace robot_simulator {

Robot::Robot() : position_({0, 0}), bearing_(Bearing::NORTH) {}

Robot::Robot(std::pair<int, int> position, Bearing bearing)
    : position_(position), bearing_(bearing) {}

std::pair<int, int> Robot::get_position() const { return position_; }
Bearing Robot::get_bearing() const { return bearing_; }

void Robot::turn_right() {
    switch (bearing_) {
        case Bearing::NORTH: bearing_ = Bearing::EAST;  break;
        case Bearing::EAST:  bearing_ = Bearing::SOUTH; break;
        case Bearing::SOUTH: bearing_ = Bearing::WEST;  break;
        case Bearing::WEST:  bearing_ = Bearing::NORTH; break;
    }
}

void Robot::turn_left() {
    switch (bearing_) {
        case Bearing::NORTH: bearing_ = Bearing::WEST;  break;
        case Bearing::WEST:  bearing_ = Bearing::SOUTH; break;
        case Bearing::SOUTH: bearing_ = Bearing::EAST;  break;
        case Bearing::EAST:  bearing_ = Bearing::NORTH; break;
    }
}

void Robot::advance() {
    switch (bearing_) {
        case Bearing::NORTH: position_.second += 1; break;
        case Bearing::EAST:  position_.first  += 1; break;
        case Bearing::SOUTH: position_.second -= 1; break;
        case Bearing::WEST:  position_.first  -= 1; break;
    }
}

void Robot::execute_sequence(const std::string& sequence) {
    for (char command : sequence) {
        switch (command) {
            case 'R': turn_right(); break;
            case 'L': turn_left();  break;
            case 'A': advance();    break;
        }
    }
}

}  // namespace robot_simulator
