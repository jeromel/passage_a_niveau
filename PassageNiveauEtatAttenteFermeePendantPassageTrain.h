#ifndef PASSAGE_NIVEAU_ETAT_ATTENTE_FERMEE_PENDANT_PASSAGE_TRAIN_H
#define PASSAGE_NIVEAU_ETAT_ATTENTE_FERMEE_PENDANT_PASSAGE_TRAIN_H

#include "PassageNiveauEtat.h"

class PassageNiveauEtatAttenteFermeePendantPassageTrain : public PassageNiveauEtat {
    public:
        void TraiterEtat();
};

#endif
