#include <iostream>
#include "lcd.hpp"
#include "rgb_lcd.h"
#include <string>
using namespace std;

lcd::lcd() : ecran()
{
    // Constructeur de la classe lcd, initialise l'objet ecran
    // de la classe rgb_lcd.
}

void lcd::write(const char* S)
{
    // Affiche le texte sur l'écran LCD.
    this->ecran.print(S);
}

void lcd::setup()
{
    // Configuration initiale de l'écran LCD.
    this->ecran.begin(16, 2);  // Initialise l'écran avec 16 colonnes et 2 lignes
    this->ecran.setColorWhite();  // Définit la couleur du texte en blanc
}

void lcd::clear()
{
    // Efface le contenu de l'écran LCD.
    this->ecran.clear();
}

void lcd::cursor(int a, int b)
{
    // Positionne le curseur de l'écran LCD à la colonne 'a' et à la ligne 'b'.
    this->ecran.setCursor(a, b);
}

void lcd::couleur(int temp)
{
    // Change la couleur de fond de l'écran LCD en fonction de la température.
    if (temp >= 30)
    {
        this->ecran.setRGB(255, 0, 0);  // Rouge
    }
    else
    {
        this->ecran.setRGB(0, 0, 255);  // Bleu
    }
}
