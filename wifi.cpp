#include "wifi.hpp"

coWifi::coWifi(const char* ssid, const char* mdp) {
  this->ssid = ssid;
  this->mdp = mdp;
}

void coWifi::connect() {
  Serial.print("Tentative de connexion au réseau WiFi ");
  Serial.println(ssid);

  WiFi.begin(ssid, mdp);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connecté");
  Serial.println("Adresse IP : " + WiFi.localIP().toString());
}
