#ifndef CAPTEUR_TEMP
#define CAPTEUR_TEMP

#include <iostream>
#include "DHT.h"

class capteurth{

public: 
  capteurth(uint8_t PIN);
  float get_temperature();
  float get_humidite();
  void setup();

private:
  DHT capteur; 
};



  #endif
