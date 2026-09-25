#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <string>
#include <unordered_map>

class Spreadsheet {
private:
    std::unordered_map<std::string, int> cells;

    int parseOperand(const std::string& op);

public:
    Spreadsheet(int rows);
    void setCell(const std::string& cell, int value);
    void resetCell(const std::string& cell);
    int getValue(const std::string& formula);
};

#endif
