#ifndef PASSAGE_NIVEAU_CONTEXTE_H
#define PASSAGE_NIVEAU_CONTEXTE_H

#include <Servo.h>
#include <Bounce2.h>

#include "Feu.h"
#include "Clignoter.h"
#include "Barriere.h"


enum mode {montee,descente,arret};
enum etat {ouvert, ferme, encours};

class PassageNiveauEtat;

class PassageNiveauContexte {
    private:
        PassageNiveauEtat *_etat;

    public:
        /***********************************************************************
        * les feux routiers
        **************************************************************************/

        Feu ** feux;
        int nombreFeux;
        
        Clignoter * clignoter;      
        
        Barriere * barriereGauche;
        Barriere * barriereDroite;

        mode sens;                          // sens du mouvement de la barriere
        etat situation;                     // situation de la barriere

        Bounce capteurOuverture;                              // anti rebond
        Bounce capteurFermeture;                              // anti rebond

        PassageNiveauContexte(PassageNiveauEtat *etat, Feu ** feux, int nombreFeux, Clignoter * clignoter, Barriere * barriereGauche, Barriere * barriereDroite) : _etat(nullptr) { 
            this->nombreFeux = nombreFeux;
            this->feux = feux;
            
            this->clignoter = clignoter;

            this->barriereGauche = barriereGauche;
            this->barriereDroite = barriereDroite;

            this->TransiterVers(etat);
        }

        ~PassageNiveauContexte() {
            delete _etat;
        }

        void TransiterVers(PassageNiveauEtat *etat);
        void TraiterFonctionDuContexte();
};

#endif
