#include <Arduino.h>

#include "PassageNiveauContexte.h"
#include "PassageNiveauEtatAttenteOuverte.h"
#include "PassageNiveauEtatAmorcerFermeture.h"

void PassageNiveauEtatAttenteOuverte::TraiterEtat() {
    Serial.println("PassageNiveauEtatAttenteOuverte");

    if (this->_contexte->capteurFermeture.fell())
    {
      this->_contexte->TransiterVers(new PassageNiveauEtatAmorcerFermeture());
    }
    
    if (Serial.available()) {
      int inputControl = Serial.read();
      if ('f' == inputControl) {
        this->_contexte->TransiterVers(new PassageNiveauEtatAmorcerFermeture());
      }
    }
}
