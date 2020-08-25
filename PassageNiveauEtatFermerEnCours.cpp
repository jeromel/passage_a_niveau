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


    int positionBarriereGauche = this->_contexte->barriereGauche->LirePositionBarriere();
    int positionBarriereDroite = this->_contexte->barriereDroite->LirePositionBarriere();
    
    Serial.print("PositionBarriereGauche: ");
    Serial.print(positionBarriereGauche);
    Serial.print(" PositionBarriereDroite: ");
    Serial.println(positionBarriereDroite);
    
    if (true == manoeuvreTermineeDroite) {    
      this->_contexte->TransiterVers(new PassageNiveauEtatAttenteFermee());
    }
}
