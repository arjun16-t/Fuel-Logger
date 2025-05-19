#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <iostream>
#include <limits>

// FOR BETTER OUTPUT
struct LogEntry {
    std::string date_time;
    float fuel;
    long odometer;
    float mileage;
};
std::ostream& operator<<(std::ostream& os, const LogEntry& entry);
LogEntry parseRow(const std::vector<std::string>& row);
void printLogHeader(std::ostream& os);

// General Usability
std::string getCurrentDateTime();
float convertToLiters(float rupees, float fuelRate = 104.05);

// CLI ENHANCEMENTS
void clearConsole();
void pauseAndWait();

// FOR FUTURE IMPLEMENTATION
// std::tm parseDateTime(const std::string& dateTimeStr);                  // For comparing logs by date (for trend/monthly analysis).
// int daysBetween(const std::string& date1, const std::string& date2);    // Used to compute refill intervals.
#endif
