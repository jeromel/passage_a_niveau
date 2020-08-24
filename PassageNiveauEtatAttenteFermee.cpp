#include <Arduino.h>

#include "PassageNiveauContexte.h"
#include "PassageNiveauEtatAttenteFermee.h"
#include "PassageNiveauEtatOuvrir.h"
#include "PassageNiveauEtatFermer.h"

void PassageNiveauEtatAttenteFermee::TraiterEtat() {
    Serial.println("PassageNiveauEtatAttenteFermee");

    if (Serial.available()) {
      int inputControl = Serial.read();
      if ('o' == inputControl) {
        this->_contexte->TransiterVers(new PassageNiveauEtatOuvrir());
      }

    }
}
