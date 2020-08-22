/*****************************************************************************
* Gestion d'une barriere dans un seul sens de direction par
* 2 capteurs un pour l'entree du train et l'autre pour la sortie, ILS, detecteur de consommation ou autre
* 2 servos de type SG90 mis tete beche sur leur cote afin de limiter leur emprise
* ce qui fait que quand un servo tourne dans un sens l'autre tourne dans l'autre sens
* et 2 feux routiers qui clignotent
***************************************************************************/

#include <Servo.h>
#include <Bounce2.h>

#include "include/moteur_barriere.h"

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

void setup()
{
  moteur_barriere_initialiser();

   pinMode(PIN_CAPTEUR_OUVRE,INPUT_PULLUP);capteurOuverture.attach(PIN_CAPTEUR_OUVRE);capteurOuverture.interval(INTERVAL);
   pinMode(PIN_CAPTEUR_FERME, INPUT_PULLUP);capteurFermeture.attach(PIN_CAPTEUR_FERME);capteurFermeture.interval(INTERVAL);
   analogWrite(PIN_FEU_DROIT,ETEINT);
   analogWrite(PIN_FEU_GAUCHE,ETEINT);

   Serial.begin(115200);
   Serial.println("On ouvre ?");
} 
 
void loop()
{    
    
   
}

void passage_a_niveau_gerer() {
  if (situation == ferme) {
    clignote();
  }
    
  if (capteurOuverture.fell()) {
    moteur_barriere_ouvrir();
  }
      
  if (capteurFermeture.fell()) {
  moteur_barriere_fermer();
  }
    
  if (situation == encours) {
    moteur_barriere_manoeuvrer();
  }
  
  capteurOuverture.update();
  capteurFermeture.update();
}
