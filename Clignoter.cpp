#include <Arduino.h>

#include "Clignoter.h"
#include "Feu.h"

void Clignoter::FaireClignoterFeux(Feu ** feuxAFaireClignoter, int nombreFeuxAFaireClignoter) {
    int indexFeu = 0;

    if (tempo + changement < millis())     // vitesse de clignotement
    {
        tempo = millis();                  // reinit le timer
        switch (cycle) {
                case 0 :
                    for(indexFeu = 0; indexFeu < nombreFeuxAFaireClignoter; ++indexFeu) {
                        feuxAFaireClignoter[indexFeu]->Allumer();
                    }                
                    cycle = 1;
                    break;
                case 1 :
                    for(indexFeu = 0; indexFeu < nombreFeuxAFaireClignoter; ++indexFeu) {
                        feuxAFaireClignoter[indexFeu]->Eteindre();
                    }                
                    cycle = 0;
                    break;
        }
    }
}
