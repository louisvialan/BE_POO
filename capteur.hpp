#ifndef CAPTEUR_HPP
#define CAPTEUR_HPP

#include <iostream>

class Sensor {
public:
    virtual int getValue() = 0;
};

#endif
