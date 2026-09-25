#include <iostream>
#include "Sphere.h"
#include "robot_simulator.h"
#include "queen_attack.h"
#include "twitter.h"
#include "spreadsheet.h"

int main() {
    std::cout << "--- 1. Sphere Class ---" << std::endl;
    Sphere s(5.0);
    std::cout << "Sphere Radius: " << s.getRadius() << std::endl;
    std::cout << "Sphere Volume: " << s.getVolume() << std::endl;
    std::cout << "Sphere Area: " << s.getSurfaceArea() << std::endl;

    std::cout << "\n--- 2. Robot Simulator ---" << std::endl;
    robot_simulator::Robot r({7, 3}, robot_simulator::Bearing::NORTH);
    r.execute_sequence("RAALAL");
    std::cout << "Robot Position: (" << r.get_position().first << ", " << r.get_position().second << ")" << std::endl;

    std::cout << "\n--- 3. Queen Attack ---" << std::endl;
    queen_attack::chess_board board({2, 3}, {5, 6});
    std::cout << "Queen Attack: " << (board.can_attack() ? "Yes" : "No") << std::endl;

    std::cout << "\n--- 4. Design Twitter ---" << std::endl;
    Twitter twitter;
    twitter.postTweet(1, 5);
    twitter.follow(1, 2);
    twitter.postTweet(2, 6);
    std::vector<int> feed = twitter.getNewsFeed(1);
    std::cout << "Twitter Feed for User 1: ";
    for (int id : feed) std::cout << id << " ";
    std::cout << std::endl;

    std::cout << "\n--- 5. Design Spreadsheet ---" << std::endl;
    Spreadsheet sheet(3);
    sheet.setCell("A1", 10);
    sheet.setCell("B2", 15);
    std::cout << "Spreadsheet '=A1+B2': " << sheet.getValue("=A1+B2") << std::endl;

    return 0;
}
