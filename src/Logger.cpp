#include "../include/Logger.h"
#include "../include/Utils.h"
constexpr int DATE_TIME = 0, FUEL = 1, ODOMETER = 2, MILEAGE = 3;
const std::string filepath = "../data/logs.csv";

// FILE HANDLING METHODS
void addLog(float fuel, long odometer) {
    
    std::ofstream fout(filepath, std::ios::app);
    if (!fout) {
        throw std::runtime_error("Error Opening File");
    }

    // Get all logs
    auto logs = viewLogs();

    float mileage = 0.0;
    if (!logs.empty()) {
        long prev_odo = std::stol(logs.back()[ODOMETER]);  // Index 2 = odometer
        mileage = (odometer - prev_odo) / fuel;
    }

    fout << getCurrentDateTime() << "," << fuel << "," << odometer << "," << mileage << "\n";
    fout.close();
}

std::vector<std::string> lastLog() {
    std::ifstream fin(filepath, std::ios::in);
    if(!fin) {
        throw std::runtime_error("Error Opening File");
    }

    std::string last_line, line;
    while(getline(fin, line)) {
        if (!line.empty())
            last_line = line;
    }
    fin.close();

    // Split last_line into parts
    std::stringstream ss(last_line);
    std::vector<std::string> lastLog;
    std::string field;
    while (getline(ss, field, ',')) {
        lastLog.push_back(field);
    }

    return lastLog;
}

std::vector<std::vector<std::string>> viewLogs() {
    std::ifstream fin (filepath, std::ios::in);
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
    fin.close();
    return logs;
}

// ANALYSIS METHODS
int getTotalLogs() {
    auto logs = viewLogs();
    return logs.size();
}

long getTotalOdo() {
    long totalOdo = 0;

    auto logs = viewLogs();
    for (const auto& log: logs) {           // row by row read
        totalOdo += std::stol(log[ODOMETER]);
    }
    return totalOdo;
}

float getTotalFuel() {
    float totalFuel = 0.0;

    auto logs = viewLogs();
    for (const auto& log: logs) {           // row by row read
        totalFuel += std::stof(log[FUEL]);
    }
    return totalFuel;
}

float getTotalAvg() {
    return getTotalOdo()/getTotalFuel();
}

std::vector<std::vector<std::string>> getMileInfo() {
    /*
    * @brief Gets Worst and Best Mileage of all the logs
    * 0 - Best Mileage
    * 1 - Worst Mileage
    */
    auto logs = viewLogs();
    if (logs.size() < 2)
        throw std::runtime_error("Not enough logs to determine mileage info.");

    float best = std::stof(logs[0][MILEAGE]);
    float worst = std::stof(logs[0][MILEAGE]);
    
    std::vector<std::vector<std::string>> mileInfo(2);
    mileInfo[0] = logs[0];
    mileInfo[1] = logs[1];

    for(size_t i = 0; i < logs.size(); i++) {
        float curr = std::stof(logs[i][MILEAGE]);
        if (curr > best) {
            best = curr;
            mileInfo[0] = logs[i];
        }
        if (curr < worst) {
            worst = curr;
            mileInfo[1] = logs[i];
        }
    }
    return mileInfo;
}


// int main() {
//     auto logs = viewLogs();
//     if (logs.empty()) {
//         std::cout << "No logs found.\n";
//     } else {
//         printLogHeader(std::cout);
//         for (const auto& log : logs) {
//             std::cout << parseRow(log) << "\n";
//         }
//     }
// }