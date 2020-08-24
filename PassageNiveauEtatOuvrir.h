#ifndef PASSAGE_NIVEAU_ETAT_OUVRIR_H
#define PASSAGE_NIVEAU_ETAT_OUVRIR_H

#include "PassageNiveauEtat.h"

#define DEBUG_MAX_FOIS_CET_ETAT 30

class PassageNiveauEtatOuvrir : public PassageNiveauEtat {

    private:
        int debugNombreFoisDansCetEtat;
        
    public:
        void TraiterEtat();
};

#endif
