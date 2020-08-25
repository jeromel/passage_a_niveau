#ifndef CLIGNOTER_H
#define CLIGNOTER_H

#include "Feu.h"

#define VITESSE_CLIGNOTEMENT 250

class Clignoter {

    private:
        int cycle = 0;                  // cycles de clignotement
        int changement;                 // vitesse de clignotement
        unsigned long tempo;         // timer pour le clignotement

    public:
        Clignoter() {
            changement = VITESSE_CLIGNOTEMENT; 
            tempo = millis();
        }

        void FaireClignoterFeux(Feu **feuxAFaireClignoter, int nombreFeuxAFaireClignoter);
};

#endif
