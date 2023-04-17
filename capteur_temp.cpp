#include <iostream>
#include "capteur_temp.hpp"
#include "DHT.h"
#define DHTTYPE DHT11


capteurth::capteurth(int PIN){
  capteur dht(PIN,DHTTYPE); 

}


float capteurth::get_temperature()
{
  float tempe;
  tempe=this->capteur.readTemperature(False);
  



  return tempe; 
};

float capteurth::get_humidite()
{
  float humidity;
  humidity=this->capteur.readHumidity();
  return humidity; 
};
