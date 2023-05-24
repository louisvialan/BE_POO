#include <iostream>
#include "capteur_temp.hpp"
#include "DHT.h"

#define DHTTYPE DHT11

#if defined(ARDUINO_ARCH_AVR)
    #define DEBUG_SERIAL  Serial
#elif defined(ARDUINO_ARCH_SAMD) ||  defined(ARDUINO_ARCH_SAM)
    #define DEBUG_SERIAL  SerialUSB
#else
    #define DEBUG_SERIAL  Serial
#endif

capteurth::capteurth(uint8_t PIN) : capteur(PIN, DHTTYPE)
{
    // Constructeur de la classe capteurth, initialise le capteur DHT
    // avec le numéro de PIN fourni.
    // DHT capteur(PIN, DHTTYPE);
}

float capteurth::get_temperature()
{
    // Récupère la température du capteur DHT.
    float temperature;
    temperature = this->capteur.readTemperature(0);
    return temperature;
}

float capteurth::get_humidite()
{
    // Récupère l'humidité du capteur DHT.
    float humidity;
    humidity = this->capteur.readHumidity();
    return humidity;
}

void capteurth::setup()
{
    // Configuration initiale du capteur DHT.
    DEBUG_SERIAL.begin(115200);  // Initialise la communication série pour le débogage
    Wire.begin();  // Initialise la communication I2C
    this->capteur.begin();  // Initialise le capteur DHT
}
