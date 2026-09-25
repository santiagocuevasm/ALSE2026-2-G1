#include "spreadsheet.h"
#include <cctype>

Spreadsheet::Spreadsheet(int rows) {}

void Spreadsheet::setCell(const std::string& cell, int value) {
    cells[cell] = value;
}

void Spreadsheet::resetCell(const std::string& cell) {
    cells.erase(cell);
}

int Spreadsheet::parseOperand(const std::string& op) {
    if (op.empty()) return 0;
    if (std::isdigit(op[0])) {
        return std::stoi(op);
    }
    return cells.count(op) ? cells[op] : 0;
}

int Spreadsheet::getValue(const std::string& formula) {
    if (formula.empty() || formula[0] != '=') return 0;

    size_t plus_pos = formula.find('+');
    if (plus_pos == std::string::npos) return 0;

    std::string left = formula.substr(1, plus_pos - 1);
    std::string right = formula.substr(plus_pos + 1);

    return parseOperand(left) + parseOperand(right);
}
