#include <iostream>
#include "air.hpp"
#include <string>
using namespace std;


air::air(int PIN):pollution(PIN)
{

}
int air::getValue()
{
  int valeur;
  valeur=this->pollution.getValue();
  
  return valeur; 
}

string air::pollutionlevel(int quality)
{
  string text; 
  

    if (quality == AirQualitySensor::FORCE_SIGNAL) {
        text="ALERTE! POLLUTION MAXIMALE!";
    } else if (quality == AirQualitySensor::HIGH_POLLUTION) {
        text="Pollution haute!";
    } else if (quality == AirQualitySensor::LOW_POLLUTION) {
        text="Pollution faible";
    } else if (quality == AirQualitySensor::FRESH_AIR) {
         text="Air frais";
    }
 
 return text; 
}

int air::pente()
{
  int val; 
  val=this->pollution.slope(); 
  return val; 
}
/*void air::setup()
{
  this->pollution.begin(9600);
}*/