#include <iostream>
#include "capteur_temp.hpp"
#include <string>
#include "air.hpp"
#include "lcd.hpp"
#include "DHT.h"
using namespace std;

capteurth patrick(D3);
lcd jeannot; 
air seb(D8);

void setup() {
    patrick.setup();
    jeannot.setup();
    //seb.setup();
}

// the loop function runs over and over again forever
void loop() {
float a,b; 
int c;
a=patrick.get_temperature(); 
b=patrick.get_humidite(); 
c=seb.getValue();
cout<<a<<" et l'humidité "<<b<<endl;

//char* temp;

//sprintf(temp,"Temperature %d",a);

string temp = "Temp=" + to_string(a);
string Hum = "Humidite=" + to_string(b);
string pollution ="Air=" + to_string(c);

jeannot.write(temp.c_str());
jeannot.cursor(0,1);
jeannot.write(Hum.c_str());
delay(1500);
jeannot.clear();
jeannot.write(pollution.c_str());
delay(1500);
jeannot.clear();
delay(1500);
}