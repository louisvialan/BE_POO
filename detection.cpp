#include <iostream>
#include "lcd.hpp"
#include "rgb_lcd.h"
#include <string>
using namespace std;
lcd::lcd():ecran(){

}

void lcd::write(const char* S)
{
  this->ecran.print(S);
}
void lcd::setup()
{
    this->ecran.begin(16, 2);
    this->ecran.setColorWhite();
}
void lcd::clear()
{
  this ->ecran.clear();
}
void lcd:: cursor(int a, int b)
{
  this ->ecran.setCursor(a,b);
}
void lcd :: couleur(int temp)
{
  if (temp>= 30)
  {
    this-> ecran.setRGB(255,0,0);
  }
  else
  {
    this->ecran.setRGB(0,0,255);
  }
    
}