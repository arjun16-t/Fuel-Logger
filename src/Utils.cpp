#include <string>
#include <ctime>
#include "../include/Utils.h"

std::string getCurrentDateTime() {
    time_t now = time(0);               // gets current time
    tm* ltm = localtime(&now);          // converts to local time
    char buffer[20];                    // to store time
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);

    return std::string(buffer);

}

//float convertToLiters(bool isRupees, float amount = 104.05);