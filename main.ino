#include <ESP8266WiFi.h>
#include <DHT.h>
#include <iostream>
#include "capteur_temp.hpp"
#include <string>
#include "air.hpp"
#include "lcd.hpp"
#include "DHT.h"
#include "Wifi.hpp"
using namespace std;


const int DAYLIGHT=0; 
const char* ssid = "iPhone de Louis";
const char* mdp = "partagelouis";

coWifi wifi(ssid, mdp);
capteurth patrick(D3);
lcd jeannot; 
air seb(D8);

void setup() {
  //Pour que le setup ne démarre que lorsqu'il fait jour
  /*int lightvalue=analogRead(A0);
  while (lightvalue<DAYLIGHT)
  {
    lightvalue=analogRead(A0);
  }
  */
    Serial.begin(115200);
    delay(10);
    patrick.setup();
    jeannot.setup();
    wifi.connect();
    //seb.setup();
}

// the loop function runs over and over again forever
void loop() {
float a,b; 
int c;
a=patrick.get_temperature(); 
b=patrick.get_humidite(); 
int quality = seb.pente();
cout<<a<<" et l'humidité "<<b<<endl;

//char* temp;

//sprintf(temp,"Temperature %d",a);

string temp = "Temp=" + to_string(a);
string Hum = "Humidite=" + to_string(b);
string pollution =seb.pollutionlevel(quality); 

jeannot.couleur(a);
jeannot.write(temp.c_str());
jeannot.cursor(0,1);
jeannot.write(Hum.c_str());
delay(1500);
jeannot.clear();
jeannot.write(pollution.c_str());
delay(1500);
jeannot.clear();
}