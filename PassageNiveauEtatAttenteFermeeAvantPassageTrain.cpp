#include <Arduino.h>

#include "PassageNiveauContexte.h"
#include "PassageNiveauEtatAttenteFermeeAvantPassageTrain.h"
#include "PassageNiveauEtatAttenteFermeePendantPassageTrain.h"
#include "PassageNiveauEtatAmorcerOuverture.h"


void PassageNiveauEtatAttenteFermeeAvantPassageTrain::TraiterEtat() {
    Serial.println("PassageNiveauEtatAttenteFermeeAvantPassageTrain");

    this->_contexte->clignoter->FaireClignoterFeux(this->_contexte->feux, this->_contexte->nombreFeux);

    if (this->_contexte->capteurOuverture.fell()) {
      this->_contexte->TransiterVers(new PassageNiveauEtatAttenteFermeePendantPassageTrain());
    }
    
    if (Serial.available()) {
      int inputControl = Serial.read();
      if ('o' == inputControl) {
        this->_contexte->TransiterVers(new PassageNiveauEtatAmorcerOuverture());
      }
    }
}
