#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <iomanip>

// FILE HANDLING METHODS
void addLog(float fuel, long odometer);
std::vector<std::string> lastLog();
std::vector<std::vector<std::string>> viewLogs();

// ANALYSIS METHODS
int getTotalLogs();
long getTotalOdo();
float getTotalFuel();
float getTotalAvg();
std::vector<std::vector<std::string>> getMileInfo();

#endif