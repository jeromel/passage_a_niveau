#include <Arduino.h>

#include "PassageNiveauContexte.h"
#include "PassageNiveauEtatAmorcerOuverture.h"
#include "PassageNiveauEtatAttenteOuverte.h"
#include "PassageNiveauEtatOuvrirEnCours.h"

void PassageNiveauEtatAmorcerOuverture::TraiterEtat() {
    Serial.println("PassageNiveauEtatAmorcerOuverture");

    this->_contexte->clignoter->FaireClignoterFeux(this->_contexte->feux, this->_contexte->nombreFeux);
    
    this->_contexte->barriereDroite->AmorcerOuverture();
    this->_contexte->barriereGauche->AmorcerOuverture();

    this->_contexte->TransiterVers(new PassageNiveauEtatOuvrirEnCours());
}
