#ifndef PASSAGE_NIVEAU_ETAT_H
#define PASSAGE_NIVEAU_ETAT_H

class PassageNiveauContexte;

class PassageNiveauEtat {
    protected:
        PassageNiveauContexte *contexte_;

    public:
        virtual ~PassageNiveauEtat() {
        }

        void setContexte(PassageNiveauContexte *contexte) {
            this->contexte_ = contexte;
        }

        virtual void TraiterEtat() = 0;
};

#endif
