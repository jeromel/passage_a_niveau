#include <Arduino.h>
#include <Bounce2.h>

#include "PassageNiveauContexte.h"
#include "PassageNiveauEtatInitialiser.h"
#include "PassageNiveauEtatAttente.h"

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

void PassageNiveauEtatInitialiser::TraiterEtat() {
    Serial.println("PassageNiveauEtatInitialiser");

    this->_contexte->angleFerme = ANGLE_FERMETURE;                     // angle de fermeture
    this->_contexte->angleOuvre = ANGLE_OUVERTURE;                     // angle pour l'ouverture
    this->_contexte->pasServo = PAS_ANGULAIRE;                         // pas angulaire
    this->_contexte->actif = false;                                   // etat de la manoeuvre                                      
    this->_contexte->duree = VITESSE_SERVO;                            // vitesse des servos            

    this->_contexte->sens = arret;                                    // sens du mouvement de la barriere
    this->_contexte->situation = ouvert;                              // situation de la barriere

    this->_contexte->servoDroitBarriere.attach(PIN_SERVO_DROIT);
    this->_contexte->servoDroitBarriere.writeMicroseconds(this->_contexte->angleOuvre);
    
    this->_contexte->servoGaucheBarriere.attach(PIN_SERVO_GAUCHE);
    this->_contexte->servoGaucheBarriere.writeMicroseconds(this->_contexte->angleFerme);

    pinMode(PIN_CAPTEUR_OUVRE,INPUT_PULLUP);
    this->_contexte->capteurOuverture.attach(PIN_CAPTEUR_OUVRE);
    this->_contexte->capteurOuverture.interval(INTERVAL);
    
    pinMode(PIN_CAPTEUR_FERME, INPUT_PULLUP);
    this->_contexte->capteurFermeture.attach(PIN_CAPTEUR_FERME);
    this->_contexte->capteurFermeture.interval(INTERVAL);

    this->_contexte->TransiterVers(new PassageNiveauEtatAttente());
}
