#include <Arduino.h>

#include "PassageNiveauContexte.h"
#include "PassageNiveauEtatAttente.h"
#include "PassageNiveauEtatOuverture.h"

void PassageNiveauEtatAttente::TraiterEtat() {
    Serial.println("PassageNiveauEtatAttente");

    this->_contexte->clignoter->FaireClignoterFeux( this->_contexte->feux, this->_contexte->nombreFeux );
}
