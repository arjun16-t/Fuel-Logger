#include "../include/Utils.h"

// FOR DISPLAYING LOGS AND HEADER
void printLogHeader(std::ostream& os) {
    os << std::left
       << std::setw(20) << "Date & Time" << " | "
       << std::setw(8)  << "Fuel(L)"     << " | "
       << std::setw(10) << "Mileage"     << " | "
       << std::setw(10) << "Odometer"
       << std::endl;

    os << std::string(60, '-') << std::endl;
}

std::ostream& operator<<(std::ostream& os, const LogEntry& entry) {
    os << std::left
       << std::setw(20) << entry.date_time << " | "
       << std::setw(8)  << std::fixed << std::setprecision(2) << entry.fuel << " | "
       << std::setw(10) << std::fixed << std::setprecision(2) << entry.mileage << " | "
       << std::setw(10) << entry.odometer
       << std::endl;
    return os;
}

LogEntry parseRow(const std::vector<std::string>& row) {
    return LogEntry{
        row[0],
        std::stof(row[1]),
        std::stol(row[2]),
        std::stof(row[3])
    };
}

std::string getCurrentDateTime() {
    time_t now = time(0);               // gets current time
    tm* ltm = localtime(&now);          // converts to local time
    char buffer[20];                    // to store time
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);

    return std::string(buffer);

}

float convertToLiters(float rupees, float fuelRate = 104.05) {
    return rupees/fuelRate;
}

// VALIDATING USER INPUT
bool isValidNumber(const std::string& str) {
    
}

// CLI ENHANCEMENTS
void clearConsole();
void pauseAndWait();