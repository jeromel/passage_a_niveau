#ifndef PASSAGE_NIVEAU_CONTEXTE_H
#define PASSAGE_NIVEAU_CONTEXTE_H

#include <iostream>

#include "/Applications/Arduino.app/Contents/Java/libraries/Servo/src/Servo.h"

enum mode {montee,descente,arret};
enum etat {ouvert, ferme, encours};

class PassageNiveauEtat;

class PassageNiveauContexte {
    private:
        PassageNiveauEtat *etat_;

    public:
        Servo servoDroitBarriere;                   // servo de la premiere barriere
        Servo servoGaucheBarriere;                  // servo de la seconde barriere

        mode sens;                          // sens du mouvement de la barriere
        etat situation;                     // situation de la barriere

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
