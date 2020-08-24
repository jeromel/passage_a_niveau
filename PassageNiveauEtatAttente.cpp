#include <Arduino.h>

#include "PassageNiveauContexte.h"
#include "PassageNiveauEtatAttente.h"
#include "PassageNiveauEtatManoeuvrer.h"

void PassageNiveauEtatAttente::TraiterEtat() {
    Serial.println("PassageNiveauEtatAttente");

    if (Serial.available()) {
      int inputControl = Serial.read();
      if ('m' == inputControl) {
        this->_contexte->TransiterVers(new PassageNiveauEtatManoeuvrer());
      }
    }
}
