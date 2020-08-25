#include <Arduino.h>
#include <Bounce2.h>

#include "PassageNiveauContexte.h"
#include "PassageNiveauEtatInitialiserCapteurs.h"
#include "PassageNiveauEtatAmorcerOuverture.h"

#define PIN_SERVO_DROIT A2  
#define PIN_SERVO_GAUCHE A3

// a regler en fonction des servos

#define VITESSE_SERVO 80
#define ANGLE_FERMETURE 1300
#define ANGLE_OUVERTURE 1900
#define PAS_ANGULAIRE 20

#define PIN_CAPTEUR_OUVRE 2  
#define PIN_CAPTEUR_FERME 3  
#define INTERVAL 50

void PassageNiveauEtatInitialiserCapteurs::TraiterEtat() {
    Serial.println("PassageNiveauEtatInitialiserCapteurs");

    pinMode(PIN_CAPTEUR_OUVRE,INPUT_PULLUP);
    this->_contexte->capteurOuverture.attach(PIN_CAPTEUR_OUVRE);
    this->_contexte->capteurOuverture.interval(INTERVAL);
    
    pinMode(PIN_CAPTEUR_FERME, INPUT_PULLUP);
    this->_contexte->capteurFermeture.attach(PIN_CAPTEUR_FERME);
    this->_contexte->capteurFermeture.interval(INTERVAL);

    this->_contexte->TransiterVers(new PassageNiveauEtatAmorcerOuverture());
}
