#ifndef PASSAGE_NIVEAU_ETAT_H
#define PASSAGE_NIVEAU_ETAT_H

class PassageNiveauContexte;

class PassageNiveauEtat {
    protected:
        PassageNiveauContexte *_contexte;

    public:
        virtual ~PassageNiveauEtat() {
        }

        void setContexte(PassageNiveauContexte *contexte) {
            this->_contexte = contexte;
        }

        virtual void TraiterEtat() = 0;
};

#endif
