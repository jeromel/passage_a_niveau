#ifndef PASSAGE_NIVEAU_ETAT_FERMER_H
#define PASSAGE_NIVEAU_ETAT_FERMER_H

#include "PassageNiveauEtat.h"

#define DEBUG_MAX_FOIS_CET_ETAT 30

class PassageNiveauEtatFermer : public PassageNiveauEtat {

    private:
        int debugNombreFoisDansCetEtat;

    public:
        void TraiterEtat();
};

#endif
