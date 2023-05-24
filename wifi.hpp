#ifndef WIFI_HPP
#define WIFI_HPP

#include <ESP8266WiFi.h>

class coWifi {
private:
  const char* ssid;
  const char* mdp;

public:
  coWifi(const char* ssid, const char* mdp);
  void connect();
};

#endif
