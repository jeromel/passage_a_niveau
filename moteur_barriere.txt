#include "include/moteur_barriere.h"

#include "Arduino.h"

/***************************************************************/
/* RAPPEL DES VARRIABLES DE GESTION DE MOUVEMENTS DES BARRIERES*/
/***************************************************************/

int angleFerme;                     // angle de fermeture
int angleOuvre;                     // angle pour l'ouverture
int angleDroit;                     // angle actuel du servo 1
int angleGauche;                    // angle actuel du servo 2
int pasServo;                       // pas angulaire
bool actif;                         // etat de la manoeuvre                                      
unsigned long timerServo;           // timer pour le servo
int duree;                          // vitesse des servos            
Servo servoDroit;                   // servo de la premiere barriere
Servo servoGauche;                  // servo de la seconde barriere

mode sens;                          // sens du mouvement de la barriere
etat situation;                     // situation de la barriere

/***************************************************************/
/***************************************************************/
/***************************************************************/

void moteur_barriere_initialiser() {
  angleFerme = ANGLE_FERMETURE;                     // angle de fermeture
  angleOuvre = ANGLE_OUVERTURE;                     // angle pour l'ouverture
  pasServo = PAS_ANGULAIRE;                         // pas angulaire
  actif = false;                                   // etat de la manoeuvre                                      
  duree = VITESSE_SERVO;                            // vitesse des servos            
  
  sens = arret;                                    // sens du mouvement de la barriere
  situation = ouvert;                              // situation de la barriere
  
  servoDroit.attach(PIN_SERVO_DROIT);servoDroit.writeMicroseconds(angleOuvre);
  servoGauche.attach(PIN_SERVO_GAUCHE);servoGauche.writeMicroseconds(angleFerme);
}

/*****************************************************************************
* ouverture de la barriere
*****************************************************************************/

void moteur_barriere_ouvrir() {
if (situation != ouvert) {                      // si pas deja ouvert
   servoDroit.attach(PIN_SERVO_DROIT);           // on attache les servos
   servoGauche.attach(PIN_SERVO_GAUCHE);  
   actif = true;                               // on devient actif          
   angleDroit = angleFerme;                    // une des barrieres va vers le bas (inversion des servos)
   angleGauche = angleOuvre;                   // l'autre en symetrie va vers le haut
   timerServo = millis();                      // MAJ du timer
   sens = montee;                              // on monte          
   situation = encours;                        // manoeuvre en cours
   }
}


/**************************************************************************
* fermeture de la barriere
***************************************************************************/

void moteur_barriere_fermer() {
if (situation != ferme ) {                      // si pas deja ferme
   servoDroit.attach(PIN_SERVO_DROIT);                          // on attach les servos
   servoGauche.attach(PIN_SERVO_GAUCHE);
   actif = true;                               // on devient actif
   angleDroit = angleOuvre;                        // une des barrieres va vers le haut (inversion des servos)
   angleGauche = angleFerme;                        // l'uatre en symetrie vers le bas
   timerServo = millis();                      // MAJ des timers
   //@TODO timerLed = millis();
   sens = descente;                            // on descend          
   situation = encours;                        // manoeuvre en cours  
   }
}

/*******************************************************************************
* manoeuvre de la barriere
*********************************************************************************/

void moteur_barriere_manoeuvrer() {
 if (actif){
   if ((timerServo + duree) < millis()){
           if (sens == montee) {
            
              angleDroit += pasServo; angleGauche -= pasServo;          // on monte
              
              if (angleDroit >= angleOuvre) {           // en bout de course
                   actif = false;                    // on n'est plus actif
                   sens = arret;                     // on est a l'arret
                   situation = ouvert;               // la barriere est ouverte
                   
                   //@TODO analogWrite(PIN_FEU_DROIT,ETEINT);           // on eteint les feux routiers
                   //@TODO analogWrite(PIN_FEU_GAUCHE,ETEINT);
                   servoDroit.detach();                  // on detache les servos
                   servoGauche.detach();
                   Serial.println("manoeuvre:montee");
                   return;
              }
           }
            
           if (sens == descente) {
                angleDroit -= pasServo; angleGauche += pasServo;      // on descend
                
                if (angleDroit <= angleFerme) {         // en bout de course
                   actif = false;                    // on n'est plus actif
                   sens = arret;                     // on est a l'arret
                   situation = ferme;                // la barriere est fermee
                   servoDroit.detach();                  // on detache les servos
                   servoGauche.detach();
                   Serial.println("manoeuvre:descente");
                   return;
                 }                          // termine
           }
           servoDroit.writeMicroseconds(angleDroit);                       // on avance de l'angle  
           servoGauche.writeMicroseconds(angleGauche);
           //@TODO analogWrite(PIN_FEU_DROIT,ALLUME);                                   // on allume les feux routiers
           //@TODO analogWrite(PIN_FEU_GAUCHE,ALLUME);
           timerServo = millis();
       }
   }
}
