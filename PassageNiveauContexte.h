#ifndef PASSAGE_NIVEAU_CONTEXTE_H
#define PASSAGE_NIVEAU_CONTEXTE_H

#include <Servo.h>
#include <Bounce2.h>

enum mode {montee,descente,arret};
enum etat {ouvert, ferme, encours};

class PassageNiveauEtat;

class PassageNiveauContexte {
    private:
        PassageNiveauEtat *etat_;

    public:
        int angleFerme;                     // angle de fermeture
        int angleOuvre;                     // angle pour l'ouverture
        int angleDroit;                     // angle actuel du servo 1
        int angleGauche;                    // angle actuel du servo 2
        int pasServo;                       // pas angulaire
        bool actif;                         // etat de la manoeuvre                                      
        unsigned long timerServo;           // timer pour le servo
        int duree;                          // vitesse des servos            
        Servo servoDroitBarriere;           // servo de la premiere barriere
        Servo servoGaucheBarriere;          // servo de la seconde barriere

        mode sens;                          // sens du mouvement de la barriere
        etat situation;                     // situation de la barriere

        Bounce capteurOuverture;                              // anti rebond
        Bounce capteurFermeture;                              // anti rebond

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
