#ifndef PASSAGE_NIVEAU_CONTEXTE_H
#define PASSAGE_NIVEAU_CONTEXTE_H

#include <iostream>

class PassageNiveauEtat;

class PassageNiveauContexte {
    private:
        PassageNiveauEtat *etat_;

    public:
        PassageNiveauContexte(PassageNiveauEtat *etat) : etat_(nullptr) {
            this->TransiterVers(etat);
        }

        ~PassageNiveauContexte() {
            delete etat_;
        }

        void TransiterVers(PassageNiveauEtat *etat);
        void TraiterFonctionDuContexte();
};

#endif
