#include <Arduino.h>

#include "PassageNiveauContexte.h"
#include "PassageNiveauEtatAttenteFermee.h"
#include "PassageNiveauEtatAmorcerOuverture.h"

void PassageNiveauEtatAttenteFermee::TraiterEtat() {
    Serial.println("PassageNiveauEtatAttenteFermee");

    this->_contexte->clignoter->FaireClignoterFeux(this->_contexte->feux, this->_contexte->nombreFeux);

    if (this->_contexte->capteurOuverture.fell()) {
      this->_contexte->TransiterVers(new PassageNiveauEtatAmorcerOuverture());
    }
    
    if (Serial.available()) {
      int inputControl = Serial.read();
      if ('o' == inputControl) {
        this->_contexte->TransiterVers(new PassageNiveauEtatAmorcerOuverture());
      }

    }
}
