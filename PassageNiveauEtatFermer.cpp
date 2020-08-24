#include <Arduino.h>

#include "PassageNiveauContexte.h"
#include "PassageNiveauEtatFermer.h"
#include "PassageNiveauEtatAttenteFermee.h"

void PassageNiveauEtatFermer::TraiterEtat() {
    Serial.println("PassageNiveauEtatFermer [");
    Serial.print(this->debugNombreFoisDansCetEtat);
    Serial.println("]");

    ++this->debugNombreFoisDansCetEtat;
    this->_contexte->clignoter->FaireClignoterFeux(this->_contexte->feux, this->_contexte->nombreFeux);

    if (this->debugNombreFoisDansCetEtat >= DEBUG_MAX_FOIS_CET_ETAT) {
      int indexFeu = 0;
      for (indexFeu = 0; indexFeu < this->_contexte->nombreFeux; ++indexFeu) {
        this->_contexte->feux[indexFeu]->Eteindre();
      }
      
      this->debugNombreFoisDansCetEtat = 0;
      this->_contexte->TransiterVers(new PassageNiveauEtatAttenteFermee());
    }
}
