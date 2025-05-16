#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

int main() {
    std::ifstream fin ("../data/logs.csv", std::ios::in);
    if(!fin) {
        throw std::runtime_error("Error Opening File");
    }

    
    std::vector<std::vector<std::string>> logs;         // to store all logs
    std::string currLine;
    getline(fin, currLine);                             // skip header

    while(getline(fin, currLine)) {
        std::vector<std::string> row;
        std::stringstream buff{currLine};
        std::string cell;

        while(getline(buff, cell, ',')) {
            row.push_back(cell);
        }
        logs.push_back(row);
    }

    for (const auto& log: logs) {
        std::cout << log.at(2);
        std::cout << "\n";
    }
    for (int i = 0; i < logs.size(); i++) {
        std::cout << logs[i][2] << std::endl;
    }
}