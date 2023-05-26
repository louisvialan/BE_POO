#ifndef AIR_HPP
#define AIR_HPP

#include <iostream>
#include "capteur.hpp"
#include "Air_Quality_Sensor.h"
#include <string>

class air : public Sensor {
public:
    air(int PIN);
    int getValue() override;
    std::string pollutionlevel(int quality);
    int pente();
    
private:
    AirQualitySensor pollution;
};

#endif

