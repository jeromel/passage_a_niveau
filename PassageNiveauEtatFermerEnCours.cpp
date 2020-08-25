#include <Arduino.h>

#include "PassageNiveauEtatFermerEnCours.h"
#include "PassageNiveauContexte.h"
#include "PassageNiveauEtatAttenteFermee.h"
#include "Barriere.h"
#include "Clignoter.h"


void PassageNiveauEtatFermerEnCours::TraiterEtat() {
    Serial.println("PassageNiveauEtatFermerEnCours");

    this->_contexte->clignoter->FaireClignoterFeux(this->_contexte->feux, this->_contexte->nombreFeux);

    bool manoeuvreTermineeDroite = this->_contexte->barriereDroite->ManoeuvrerFermer();
    bool manoeuvreTermineeGauche = this->_contexte->barriereGauche->ManoeuvrerFermer();
    
    if (true == manoeuvreTermineeDroite) {    
      this->_contexte->TransiterVers(new PassageNiveauEtatAttenteFermee());
    }
}
