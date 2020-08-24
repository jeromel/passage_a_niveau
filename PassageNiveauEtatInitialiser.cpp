#include <Arduino.h>
#include <Bounce2.h>
#include "PassageNiveauContexte.h"
#include "PassageNiveauEtatInitialiser.h"

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

    this->contexte_->angleFerme = ANGLE_FERMETURE;                     // angle de fermeture
    this->contexte_->angleOuvre = ANGLE_OUVERTURE;                     // angle pour l'ouverture
    this->contexte_->pasServo = PAS_ANGULAIRE;                         // pas angulaire
    this->contexte_->actif = false;                                   // etat de la manoeuvre                                      
    this->contexte_->duree = VITESSE_SERVO;                            // vitesse des servos            

    this->contexte_->sens = arret;                                    // sens du mouvement de la barriere
    this->contexte_->situation = ouvert;                              // situation de la barriere

    this->contexte_->servoDroitBarriere.attach(PIN_SERVO_DROIT);
    this->contexte_->servoDroitBarriere.writeMicroseconds(this->contexte_->angleOuvre);
    
    this->contexte_->servoGaucheBarriere.attach(PIN_SERVO_GAUCHE);
    this->contexte_->servoGaucheBarriere.writeMicroseconds(this->contexte_->angleFerme);

    pinMode(PIN_CAPTEUR_OUVRE,INPUT_PULLUP);
    this->contexte_->capteurOuverture.attach(PIN_CAPTEUR_OUVRE);
    this->contexte_->capteurOuverture.interval(INTERVAL);
    
    pinMode(PIN_CAPTEUR_FERME, INPUT_PULLUP);
    this->contexte_->capteurFermeture.attach(PIN_CAPTEUR_FERME);
    this->contexte_->capteurFermeture.interval(INTERVAL);
}
