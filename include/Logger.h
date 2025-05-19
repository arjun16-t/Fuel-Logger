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

/*
MORE ANALYSIS METHODS TO IMPLEMENT
1) Monthly Fuel Consumption
2) Days Between FillUps
3) Average Mileage per month
4) Total Cost Estimation (include cost column)
5) Longest Trip
6) Shortest Trip
------ ADVANCED ------
7) Mileage Trend
8) Abnormal Mileage Detection

*/

#endif