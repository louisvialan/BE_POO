#include <iostream>
#include "air.hpp"
#include <string>
using namespace std;

air::air(int PIN) : pollution(PIN)
{
    // Constructeur de la classe air, initialise le capteur de pollution
    // avec le numéro de PIN fourni.
}

int air::getValue()
{
    // Récupère la valeur de pollution mesurée par le capteur.
    int valeur;
    valeur = this->pollution.getValue();
    return valeur;
}

string air::pollutionlevel(int quality)
{
    // Détermine le niveau de pollution en fonction de la qualité de l'air mesurée.
    // Retourne une chaîne de caractères descriptive du niveau de pollution.
    string text;

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
    // Calcule la pente de variation de la pollution mesurée.
    int val;
    val = this->pollution.slope();
    return val;
}

/*void air::setup()
{
    // Configuration initiale du capteur de pollution.
    this->pollution.begin(9600);
}*/
