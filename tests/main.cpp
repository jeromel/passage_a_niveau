#include <iostream>

#include "../PassageNiveauContexte.h"
#include "../PassageNiveauEtatInitialiser.h"

PassageNiveauContexte *contexte;


void setup() {
    contexte  = new PassageNiveauContexte(new PassageNiveauEtatInitialiser());
    contexte->TraiterFonctionDuContexte();
}

void loop() {

}

void simulerArduino() {
    char inputKeyboard = ' ';

    setup();

    do {
        loop();
        inputKeyboard = getchar();
    }
    while ('q' != inputKeyboard);
}

int main(void) {
    
    simulerArduino();
    

    delete contexte;

    return EXIT_SUCCESS;
}