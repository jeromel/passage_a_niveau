#include <Arduino.h>

#include "PassageNiveauContexte.h"
#include "PassageNiveauEtatAttenteFermeePendantPassageTrain.h"
#include "PassageNiveauEtatAmorcerOuverture.h"

void PassageNiveauEtatAttenteFermeePendantPassageTrain::TraiterEtat() {
    Serial.println("PassageNiveauEtatAttenteFermeePendantPassageTrain");

    this->_contexte->clignoter->FaireClignoterFeux(this->_contexte->feux, this->_contexte->nombreFeux);

    if (this->_contexte->capteurOuverture.rose()) {
      this->_contexte->TransiterVers(new PassageNiveauEtatAmorcerOuverture());
    }
    
    if (Serial.available()) {
      int inputControl = Serial.read();
      if ('o' == inputControl) {
        this->_contexte->TransiterVers(new PassageNiveauEtatAmorcerOuverture());
      }

    }
}
