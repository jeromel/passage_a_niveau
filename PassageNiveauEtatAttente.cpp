#include <Arduino.h>

#include "PassageNiveauContexte.h"
#include "PassageNiveauEtatAttente.h"
#include "PassageNiveauEtatOuverture.h"

void PassageNiveauEtatAttente::TraiterEtat() {
    Serial.println("PassageNiveauEtatAttente");

    this->contexte_->TransiterVers(new PassageNiveauEtatOuverture());
}
