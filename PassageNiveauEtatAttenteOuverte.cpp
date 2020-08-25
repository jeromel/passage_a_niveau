#include <Arduino.h>

#include "PassageNiveauContexte.h"
#include "PassageNiveauEtatAttenteOuverte.h"
#include "PassageNiveauEtatAmorcerFermeture.h"

void PassageNiveauEtatAttenteOuverte::TraiterEtat() {
    Serial.println("PassageNiveauEtatAttenteOuverte");

    if (Serial.available()) {
      int inputControl = Serial.read();
      if ('f' == inputControl) {
        this->_contexte->TransiterVers(new PassageNiveauEtatAmorcerFermeture());
      }
    }
}
