#include "wifi.hpp"


coWifi::coWifi(const char* ssid, const char* mdp) {
    // Constructeur de la classe coWifi, initialise les informations du réseau WiFi.
    this->ssid = ssid;
    this->mdp = mdp;
}

void coWifi::connect() {
    // Connecte l'ESP8266 au réseau WiFi spécifié.

    // Affiche le SSID du réseau WiFi auquel on se connecte
    Serial.print("Tentative de connexion au réseau WiFi ");
    Serial.println(ssid);

    // Démarre la connexion au réseau WiFi
    WiFi.begin(ssid, mdp);

    // Attends que la connexion soit établie
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connecté");
    Serial.println("Adresse IP : " + WiFi.localIP().toString());
}
