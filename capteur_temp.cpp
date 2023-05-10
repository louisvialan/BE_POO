#include <iostream>
#include "capteur_temp.hpp"
#include "DHT.h"
#define DHTTYPE DHT11
#if defined(ARDUINO_ARCH_AVR)
    #define debug  Serial

#elif defined(ARDUINO_ARCH_SAMD) ||  defined(ARDUINO_ARCH_SAM)
    #define debug  SerialUSB
#else
    #define debug  Serial
#endif


capteurth::capteurth(uint8_t PIN): capteur(PIN,DHTTYPE)
{
  //DHT capteur(PIN,DHTTYPE); 
}


float capteurth::get_temperature()
{
  float tempe;
  tempe=this->capteur.readTemperature(0);
  
  return tempe; 
};

float capteurth::get_humidite()
{
  float humidity;
  humidity=this->capteur.readHumidity();
  return humidity; 
};
void capteurth::setup()
{
  
    debug.begin(115200);
    //debug.println("DHTxx test!");
    Wire.begin();
    /*if using WIO link,must pull up the power pin.*/
    // pinMode(PIN_GROVE_POWER, OUTPUT);
    // digitalWrite(PIN_GROVE_POWER, 1);
    this->capteur.begin();
}