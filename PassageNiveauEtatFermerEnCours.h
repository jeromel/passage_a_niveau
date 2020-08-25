#ifndef PASSAGE_NIVEAU_ETAT_MANOEUVRER_FERMER_H
#define PASSAGE_NIVEAU_ETAT_MANOEUVRER_FERMER_H

#include "PassageNiveauEtat.h"

#define DEBUG_MAX_FOIS_CET_ETAT 30

class PassageNiveauEtatFermerEnCours : public PassageNiveauEtat {

    private:
        int debugNombreFoisDansCetEtat;

    public:
        void TraiterEtat();
};

#endif
