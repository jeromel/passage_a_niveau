#ifndef PASSAGE_NIVEAU_CONTEXTE_H
#define PASSAGE_NIVEAU_CONTEXTE_H

#include <Servo.h>
#include <Bounce2.h>

#include "Feu.h"
#include "Clignoter.h"

#define PIN_FEU_DROIT 4
#define PIN_FEU_GAUCHE 5

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

        PassageNiveauContexte(PassageNiveauEtat *etat) : _etat(nullptr) { 
            nombreFeux = 2;
            feux = (Feu **) malloc(sizeof(Feu *) * nombreFeux);
            
            feux[0] = new Feu(PIN_FEU_GAUCHE);
            feux[1] = new Feu(PIN_FEU_DROIT);
            
            this->clignoter = new Clignoter();

            this->TransiterVers(etat);
        }

        ~PassageNiveauContexte() {
            delete _etat;

            int indexFeu = 0;

            for (indexFeu = 0; indexFeu < nombreFeux; ++indexFeu) {
              free(this->feux[indexFeu]);
            }

            free(this->feux);
        }

        void TransiterVers(PassageNiveauEtat *etat);
        void TraiterFonctionDuContexte();
};

#endif
