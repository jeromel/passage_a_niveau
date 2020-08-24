#include <Arduino.h>

#include "PassageNiveauEtat.h"
#include "PassageNiveauContexte.h"

void PassageNiveauContexte::TransiterVers(PassageNiveauEtat *etat) {
    if (this->_etat != nullptr) {
        delete this->_etat;
    }

    this->_etat = etat;
    this->_etat->setContexte(this);
}

void PassageNiveauContexte::TraiterFonctionDuContexte() {
    this->_etat->TraiterEtat();
}
