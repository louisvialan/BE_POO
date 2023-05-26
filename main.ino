#include <ESP8266WiFi.h>
#include <DHT.h>
#include <iostream>
#include <string>
#include "capteur_temp.hpp"
#include "air.hpp"
#include "lcd.hpp"
#include "Wifi.hpp"
#include <WiFiUdp.h>

using namespace std;

// Constante de luminosité du jour
const int DAYLIGHT = 0;

// Informations de connexion WiFi
const char* ssid = "Meteo";
const char* mdp = "12345678";

//Information port UDP 

#define UDP_PORT 3111

// Instanciation des objets
WiFiUDP UDP;  // UDP
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
    UDP.begin(UDP_PORT);
    Serial.print("Listening on UDP port ");
    Serial.println(UDP_PORT);
 
}



 char packet[255];
 const char * reply; 
 char test[]="temp";
 string sreply; //Variables de communication UDP
 float temperature, humidite;
 int quality;

void loop() {
  
   
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


     // Si un paquet envoyé par l'appli est reçu
  int packetSize = UDP.parsePacket();
  if (packetSize) {
    Serial.print("Paquet reçu!"); 
    int len = UDP.read(packet, 255);
    if (len > 0)
    {
      packet[len] = '\0';
    }
    // Send return packet
    delay(1000);
    Serial.print("Paquet envoyé");
    UDP.beginPacket(UDP.remoteIP(), UDP.remotePort());
    sreply=tempString+"   "+humString;
    if (temperature>30) {sreply="ALERTE!";}
    reply=sreply.c_str();
    UDP.write(reply);
    UDP.endPacket();

  }
}
