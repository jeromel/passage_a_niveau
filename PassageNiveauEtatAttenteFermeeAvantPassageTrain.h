#ifndef PASSAGE_NIVEAU_ETAT_ATTENTE_FERMEE_AVANT_PASSAGE_TRAIN_H
#define PASSAGE_NIVEAU_ETAT_ATTENTE_FERMEE_AVANT_PASSAGE_TRAIN_H

#include "PassageNiveauEtat.h"

class PassageNiveauEtatAttenteFermeeAvantPassageTrain : public PassageNiveauEtat {
    public:
        void TraiterEtat();
};

#endif
