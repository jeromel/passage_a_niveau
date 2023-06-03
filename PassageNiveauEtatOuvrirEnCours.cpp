#include <Arduino.h>

#include "PassageNiveauContexte.h"
#include "PassageNiveauEtatOuvrirEnCours.h"
#include "PassageNiveauEtatAttenteOuverte.h"
#include "Barriere.h"

void PassageNiveauEtatOuvrirEnCours::TraiterEtat() {
    Serial.println("PassageNiveauEtatOuvrirEnCours");

    bool manoeuvreTermineeDroite = this->_contexte->barriereDroite->ManoeuvrerOuvrir();
    bool manoeuvreTermineeGauche = this->_contexte->barriereGauche->ManoeuvrerOuvrir();

    this->_contexte->clignoter->FaireClignoterFeux(this->_contexte->feux, this->_contexte->nombreFeux);
    
    int positionBarriereGauche = this->_contexte->barriereGauche->LirePositionBarriere();
    int positionBarriereDroite = this->_contexte->barriereDroite->LirePositionBarriere();

    Serial.print("PositionBarriereGauche: ");
    Serial.print(positionBarriereGauche);
    Serial.print(" PositionBarriereDroite: ");
    Serial.println(positionBarriereDroite);
    
    if (true == manoeuvreTermineeDroite) {    
      int indexFeu = 0;
      for (indexFeu = 0; indexFeu < this->_contexte->nombreFeux; ++indexFeu) {
        this->_contexte->feux[indexFeu]->Eteindre();
      }
      
      this->_contexte->TransiterVers(new PassageNiveauEtatAttenteOuverte());
    }
}