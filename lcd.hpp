#ifndef LCD_HPP
#define LCD_HPP

#include <iostream>
#include "rgb_lcd.h"
#include <string>
using namespace std;

class lcd {

public: 
  lcd ();
  void write(const char* S );
  void color();
  void clear();
  void setup();
  void cursor(int a, int b);
  
private: 
  rgb_lcd ecran; 
};
#endif