#include <Arduino.h>

#include "Feu.h"

#define ALLUME 0
#define ETEINT 255

void Feu::Allumer() {
    analogWrite(_numeroPin,ALLUME);
}

void Feu::Eteindre() {
    analogWrite(_numeroPin,ETEINT);
}