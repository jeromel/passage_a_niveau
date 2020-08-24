#include <Arduino.h>

#include "Feu.h"

#define ALLUME 255
#define ETEINT 0

void Feu::Allumer() {
    analogWrite(_numeroPin,ALLUME);
}

void Feu::Eteindre() {
    analogWrite(_numeroPin,ETEINT);
}
