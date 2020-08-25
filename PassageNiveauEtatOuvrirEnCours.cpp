#include <Arduino.h>

#include "PassageNiveauContexte.h"
#include "PassageNiveauEtatOuvrirEnCours.h"
#include "PassageNiveauEtatAttenteOuverte.h"
#include "Barriere.h"

void PassageNiveauEtatOuvrirEnCours::TraiterEtat() {
    Serial.println("PassageNiveauEtatOuvrirEnCours");

    bool manoeuvreTermineeDroite = this->_contexte->barriereDroite->ManoeuvrerOuvrir();
    bool manoeuvreTermineeGauche = this->_contexte->barriereGauche->ManoeuvrerOuvrir();
    
    if (true == manoeuvreTermineeDroite) {    
      int indexFeu = 0;
      for (indexFeu = 0; indexFeu < this->_contexte->nombreFeux; ++indexFeu) {
        this->_contexte->feux[indexFeu]->Eteindre();
      }
      
      this->_contexte->TransiterVers(new PassageNiveauEtatAttenteOuverte());
    }
}
