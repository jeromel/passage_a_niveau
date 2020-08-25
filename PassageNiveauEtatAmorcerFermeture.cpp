#include <Arduino.h>

#include "PassageNiveauContexte.h"
#include "PassageNiveauEtatAmorcerFermeture.h"
#include "PassageNiveauEtatFermerEnCours.h"

void PassageNiveauEtatAmorcerFermeture::TraiterEtat() {
    Serial.println("PassageNiveauEtatAmorcerFermeture");
    
    this->_contexte->clignoter->FaireClignoterFeux(this->_contexte->feux, this->_contexte->nombreFeux);

    this->_contexte->barriereDroite->AmorcerFermeture();
    this->_contexte->barriereGauche->AmorcerFermeture();

    this->_contexte->TransiterVers(new PassageNiveauEtatFermerEnCours());
}
