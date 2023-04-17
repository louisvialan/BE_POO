#ifndef CAPTEUR_TEMP
#define CAPTEUR_TEMP

#include <iostream>
#include "DHT.h"

class capteurth{

public: 
  capteurth(int PIN);
  float get_temperature();
  float get_humidite();

private:
  DHT capteur; 


};



  #endif
