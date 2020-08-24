#ifndef PASSAGE_NIVEAU_ETAT_MANOEUVRER_H
#define PASSAGE_NIVEAU_ETAT_MANOEUVRER_H

#include "PassageNiveauEtat.h"

#define DEBUG_MAX_FOIS_CET_ETAT 50

class PassageNiveauEtatManoeuvrer : public PassageNiveauEtat {
    private:
        int debugNombreFoisDansCetEtat;

    public:
        PassageNiveauEtatManoeuvrer() {
            debugNombreFoisDansCetEtat = 0;
        }
        
        void TraiterEtat();
};

#endif
