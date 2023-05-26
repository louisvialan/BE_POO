#include <iostream>
#include "air.hpp"
#include <string>

air::air(int PIN) : pollution(PIN)
{
    // Constructor of the air class, initializes the pollution sensor
    // with the provided PIN number.
}

int air::getValue()
{
    // Retrieves the pollution value measured by the sensor.
    int value = pollution.getValue();
    return value;
}

std::string air::pollutionlevel(int quality)
{
    // Determines the pollution level based on the measured air quality.
    // Returns a descriptive string of the pollution level.
    std::string text;

    if (quality == AirQualitySensor::FORCE_SIGNAL) {
        text = "ALERTE ! POLLUTION MAXIMALE !";
    } else if (quality == AirQualitySensor::HIGH_POLLUTION) {
        text = "Pollution élevée !";
    } else if (quality == AirQualitySensor::LOW_POLLUTION) {
        text = "Pollution faible.";
    } else if (quality == AirQualitySensor::FRESH_AIR) {
        text = "Air agréable.";
    }
 
    return text;
}

int air::pente()
{
    // Calculates the slope of the pollution variation.
    int val = pollution.slope();
    return val;
}

