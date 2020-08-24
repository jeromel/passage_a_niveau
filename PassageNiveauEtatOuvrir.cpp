#include <Arduino.h>

#include "PassageNiveauContexte.h"
#include "PassageNiveauEtatOuvrir.h"
#include "PassageNiveauEtatAttenteOuverte.h"

void PassageNiveauEtatOuvrir::TraiterEtat() {
    Serial.println("PassageNiveauEtatOuvrir [");
    Serial.print(this->debugNombreFoisDansCetEtat);
    Serial.println("]");

    int indexFeu = 0;
    for (indexFeu = 0; indexFeu < this->_contexte->nombreFeux; ++indexFeu) {
      this->_contexte->feux[indexFeu]->Eteindre();
    }

    ++this->debugNombreFoisDansCetEtat;

    if (this->debugNombreFoisDansCetEtat >= DEBUG_MAX_FOIS_CET_ETAT) {
      this->debugNombreFoisDansCetEtat = 0;
      this->_contexte->TransiterVers(new PassageNiveauEtatAttenteOuverte());
    }
}
