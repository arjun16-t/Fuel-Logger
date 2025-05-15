#pragma once
#include <string>

class FuelLog {
private:
    float fuelLiters;
    float odometerReading;
    std::string timestamp;

public:
    FuelLog(float fuel, float odo, const std::string& time);
    
    float getFuel() const;
    float getOdometer() const;
    std::string getTimestamp() const;

    static FuelLog fromString(const std::string& line); // For reading from file
    static FuelLog total_entry();
    std::string toString() const; // For writing to file
};
