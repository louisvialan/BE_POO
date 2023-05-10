#include <iostream>
#include "air.hpp"
#include <string>
using namespace std;


air::air(int PIN):pollution(PIN)
{

}
int air::getValue()
{
  int valeur;
  valeur=this->pollution.getValue();
  
  return valeur; 
}
/*void air::setup()
{
  this->pollution.begin(9600);
}*/