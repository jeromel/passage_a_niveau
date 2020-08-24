#include <iostream>

#include "PassageNiveauContexte.h"
#include "PassageNiveauEtatAttente.h"
#include "PassageNiveauEtatOuverture.h"

void PassageNiveauEtatAttente::TraiterEtat() {
    std::cout << "PassageNiveauEtatAttente";

    this->contexte_->TransiterVers(new PassageNiveauEtatOuverture());
}
