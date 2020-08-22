/*****************************************************************************
* Gestion d'une barriere dans un seul sens de direction par
* 2 capteurs un pour l'entree du train et l'autre pour la sortie, ILS, detecteur de consommation ou autre
* 2 servos de type SG90 mis tete beche sur leur cote afin de limiter leur emprise
* ce qui fait que quand un servo tourne dans un sens l'autre tourne dans l'autre sens
* et 2 feux routiers qui clignotent
***************************************************************************/


#include <Servo.h>
#include <Bounce2.h>

#define PIN_CAPTEUR_OUVRE 2  
#define PIN_CAPTEUR_FERME 3  
#define INTERVAL 50

#define PIN_FEU_DROIT 4
#define PIN_FEU_GAUCHE 5
#define ALLUME 0
#define ETEINT 255
#define VITESSE_CLIGNOTEMENT 250

#define PIN_SERVO_DROIT A2  
#define PIN_SERVO_GAUCHE A3

// a regler en fonction des servos

#define VITESSE_SERVO 80
#define ANGLE_FERMETURE 1300
#define ANGLE_OUVERTURE 1900
#define PAS_ANGULAIRE 20

/***********************************************************************
* les feux routiers
**************************************************************************/

int cycle = 0;                                        // cycles de clignotement
int changement = VITESSE_CLIGNOTEMENT;                // vitesse de clignotement
unsigned long timerLed = millis();                    // timer pour le clignotement

/******************************************************************************
* les capteurs
********************************************************************************/

Bounce capteurOuverture;                              // anti rebond
Bounce capteurFermeture;                              // anti rebond

/************************************************************************************
* les servos
**************************************************************************************/

int angleFerme = ANGLE_FERMETURE;                     // angle de fermeture
int angleOuvre = ANGLE_OUVERTURE;                     // angle pour l'ouverture
int angleDroit;                                       // angle actuel du servo 1
int angleGauche;                                      // angle actuel du servo 2
int pasServo = PAS_ANGULAIRE;                         // pas angulaire
enum mode {montee,descente,arret};
mode sens = arret;                                    // sens du mouvement de la barriere
enum etat {ouvert, ferme, encours};
etat situation = ouvert;                              // situation de la barriere
bool actif = false;                                   // etat de la manoeuvre                                      
unsigned long timerServo;                             // timer pour le servo
int duree = VITESSE_SERVO;                            // vitesse des servos            
Servo servoDroit;                                     // servo de la premiere barriere
Servo servoGauche;                                    // servo de la seconde barriere

/*****************************************************************************
* clignotement des feux routiers
***************************************************************************/

void clignote() {
if (timerLed + changement < millis())     // vitesse de clignotement
   {
   timerLed = millis();                  // reinit le timer
   switch (cycle) {
           case 0 : {analogWrite(PIN_FEU_DROIT,ALLUME); analogWrite(PIN_FEU_GAUCHE,ALLUME);cycle = 1;break;}      // on allume
           case 1 : {analogWrite(PIN_FEU_DROIT,ETEINT); analogWrite(PIN_FEU_GAUCHE,ETEINT);cycle = 0;break;}      // on eteint
       }
   }
}

/*****************************************************************************
* initialisation de l'ouverture des barrieres
*****************************************************************************/

void ouverture() {
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
* initialisation de la fermeture des barrieres
***************************************************************************/

void fermeture() {
if (situation != ferme ) {                      // si pas deja ferme
   servoDroit.attach(PIN_SERVO_DROIT);                          // on attach les servos
   servoGauche.attach(PIN_SERVO_GAUCHE);
   actif = true;                               // on devient actif
   angleDroit = angleOuvre;                        // une des barrieres va vers le haut (inversion des servos)
   angleGauche = angleFerme;                        // l'uatre en symetrie vers le bas
   timerServo = millis();                      // MAJ des timers
   timerLed = millis();
   sens = descente;                            // on descend          
   situation = encours;                        // manoeuvre en cours  
   }
}

/*******************************************************************************
* manoeuvre de la bbariere
*********************************************************************************/

void manoeuvre() {
 if (actif){
   if ((timerServo + duree) < millis()){             // vitesse des servos
           if (sens == montee) {angleDroit += pasServo; angleGauche -= pasServo;          // on monte
                               if (angleDroit >= angleOuvre) {           // en bout de course
                                   actif = false;                    // on n'est plus actif
                                   sens = arret;                     // on est a l'arret
                                   situation = ouvert;               // la barriere est ouverte
                                   analogWrite(PIN_FEU_DROIT,ETEINT);           // on eteint les feux routiers
                                   analogWrite(PIN_FEU_GAUCHE,ETEINT);
                                   servoDroit.detach();                  // on detache les servos
                                   servoGauche.detach();
                                   Serial.println("manoeuvre:montee");
                                   return;}                          // termine
                               }
           if (sens == descente) {angleDroit -= pasServo; angleGauche += pasServo;      // on descend
                               if (angleDroit <= angleFerme) {         // en bout de course
                                 actif = false;                    // on n'est plus actif
                                 sens = arret;                     // on est a l'arret
                                 situation = ferme;                // la barriere est fermee
                                 servoDroit.detach();                  // on detache les servos
                                 servoGauche.detach();
                                 Serial.println("manoeuvre:descente");
                                 return;}                          // termine
                               }
           servoDroit.writeMicroseconds(angleDroit);                       // on avance de l'angle  
           servoGauche.writeMicroseconds(angleGauche);
           analogWrite(PIN_FEU_DROIT,ALLUME);                                   // on allume les feux routiers
           analogWrite(PIN_FEU_GAUCHE,ALLUME);
           timerServo = millis();
       }
   }
}

/*******************************************************************
* setup
******************************************************************/

void setup()
{
   servoDroit.attach(PIN_SERVO_DROIT);servoDroit.writeMicroseconds(angleOuvre);
   servoGauche.attach(PIN_SERVO_GAUCHE);servoGauche.writeMicroseconds(angleFerme);
   pinMode(PIN_CAPTEUR_OUVRE,INPUT_PULLUP);capteurOuverture.attach(PIN_CAPTEUR_OUVRE);capteurOuverture.interval(INTERVAL);
   pinMode(PIN_CAPTEUR_FERME, INPUT_PULLUP);capteurFermeture.attach(PIN_CAPTEUR_FERME);capteurFermeture.interval(INTERVAL);
   analogWrite(PIN_FEU_DROIT,ETEINT);
   analogWrite(PIN_FEU_GAUCHE,ETEINT);

   Serial.begin(115200);
   Serial.println("On ouvre ?");
} 

/*******************************************************************
 * la boucle
 ********************************************************************/
 
void loop()
{    
    if (situation == ferme) { Serial.print("situation :"); Serial.println("ferme"); clignote();}
    if (capteurOuverture.fell()) {Serial.println("ouverture"); ouverture();}
    if (capteurFermeture.fell()) {Serial.println("fermeture"); fermeture();}
    if (situation == encours) {Serial.print("situation :"); Serial.println("encours"); manoeuvre();}
    capteurOuverture.update();
    capteurFermeture.update();
   
}
