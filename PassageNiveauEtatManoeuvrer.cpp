#include <Arduino.h>

#include "PassageNiveauContexte.h"
#include "PassageNiveauEtatManoeuvrer.h"
#include "PassageNiveauEtatAttente.h"

void PassageNiveauEtatManoeuvrer::TraiterEtat() {
    Serial.print("PassageNiveauEtatManoeuvrer [");
    Serial.print(this->debugNombreFoisDansCetEtat);
    Serial.println("]");

    ++this->debugNombreFoisDansCetEtat;
    this->_contexte->clignoter->FaireClignoterFeux(this->_contexte->feux, this->_contexte->nombreFeux);

    if (this->debugNombreFoisDansCetEtat >= DEBUG_MAX_FOIS_CET_ETAT) {
      this->debugNombreFoisDansCetEtat = 0;
      this->_contexte->TransiterVers(new PassageNiveauEtatAttente());
    }
}
