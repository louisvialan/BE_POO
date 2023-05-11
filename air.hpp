#ifndef AIR_HPP
#define AIR_HPP

#include <iostream>
#include "Air_Quality_Sensor.h"
#include <string>
using namespace std;

class air {

public: 
  air(int PIN);
  int getValue();
  string pollutionlevel(int quality); 
  int pente();
  //void setup();

private: 
  AirQualitySensor pollution; 
};

#endif