#include <ESP8266WiFi.h>
#include <DHT.h>
#include <iostream>
#include <string>
#include "capteur_temp.hpp"
#include "air.hpp"
#include "lcd.hpp"
#include "Wifi.hpp"

using namespace std;

// Constante de luminosité du jour
const int DAYLIGHT = 0;

// Informations de connexion WiFi
const char* ssid = "iPhone de Louis";
const char* mdp = "partagelouis";

// Instanciation des objets
coWifi wifi(ssid, mdp);  // Objet pour la gestion du WiFi
capteurth patrick(D3);  // Objet pour le capteur de température et d'humidité
lcd jeannot;  // Objet pour l'écran LCD
air seb(D8);  // Objet pour la qualité de l'air

void setup() {
    Serial.begin(115200);
    delay(10);

    // Initialisation des objets
    patrick.setup();
    jeannot.setup();
    wifi.connect();
}

void loop() {
    float temperature, humidite;
    int quality;

    // Récupération des données du capteur de température et d'humidité
    temperature = patrick.get_temperature();
    humidite = patrick.get_humidite();

    // Calcul de la qualité de l'air
    quality = seb.pente();

    // Affichage des valeurs sur le moniteur série
    cout << "Température : " << temperature << " °C" << endl;
    cout << "Humidité : " << humidite << " %" << endl;

    // Création des chaînes de caractères pour affichage sur l'écran LCD
    string tempString = "Temp = " + to_string(temperature) + " C";
    string humString = "Humidite = " + to_string(humidite) + " %";
    string pollutionLevel = seb.pollutionlevel(quality);

    // Affichage sur l'écran LCD
    jeannot.couleur(temperature);  // Changer la couleur de l'écran en fonction de la température
    jeannot.write(tempString.c_str());  // Afficher la température
    jeannot.cursor(0, 1);
    jeannot.write(humString.c_str());  // Afficher l'humidité
    delay(1500);
    jeannot.clear();

    // Affichage du niveau de pollution sur l'écran LCD
    jeannot.write(pollutionLevel.c_str());
    delay(1500);
    jeannot.clear();
}
