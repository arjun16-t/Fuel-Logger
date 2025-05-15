#include "../include/Logger.h"
#include "../include/Utils.h"

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
        long prev_odo = std::stol(logs.back()[2]);  // Index 2 = odometer
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
    fin.close();
    return logs;
}

// ANALYSIS METHODS
void showStats();