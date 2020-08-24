#include "PassageNiveauEtat.h"
#include "PassageNiveauContexte.h"

void PassageNiveauContexte::TransiterVers(PassageNiveauEtat *etat) {
    std::cout << "Contexte: TransitionVers " << typeid(*etat).name() << ".\n";
    if (this->etat_ != nullptr) {
        delete this->etat_;
    }

    this->etat_ = etat;
    this->etat_->setContexte(this);
}

void PassageNiveauContexte::TraiterFonctionDuContexte() {
    this->etat_->TraiterEtat();
}