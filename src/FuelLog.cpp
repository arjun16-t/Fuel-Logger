#include "FuelLog.h"

FuelLog::FuelLog (float fuel, float odo, const std::string& time) {
    this->fuelLiters = fuel;
    this->odometerReading = odo;
    this->timestamp = time;
}
    
float FuelLog::getFuel() const {
    return fuelLiters;
}
float FuelLog::getOdometer() const {
    return odometerReading;
}
std::string FuelLog::getTimestamp() const {
    return timestamp;
}