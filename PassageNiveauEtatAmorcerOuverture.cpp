#include <Arduino.h>

#include "PassageNiveauContexte.h"
#include "PassageNiveauEtatAmorcerOuverture.h"
#include "PassageNiveauEtatAttenteOuverte.h"
#include "PassageNiveauEtatOuvrirEnCours.h"

void PassageNiveauEtatAmorcerOuverture::TraiterEtat() {
    Serial.println("PassageNiveauEtatAmorcerOuverture");

    int indexFeu = 0;
    for (indexFeu = 0; indexFeu < this->_contexte->nombreFeux; ++indexFeu) {
      this->_contexte->feux[indexFeu]->Eteindre();
    }

    this->_contexte->barriereDroite->AmorcerOuverture();
    this->_contexte->barriereGauche->AmorcerOuverture();

    this->_contexte->TransiterVers(new PassageNiveauEtatOuvrirEnCours());
}
