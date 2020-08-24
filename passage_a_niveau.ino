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

/******************************************************************************
* les capteurs
********************************************************************************/

Bounce capteurOuverture;                              // anti rebond
Bounce capteurFermeture;                              // anti rebond


#include "PassageNiveauContexte.h"
#include "PassageNiveauEtatInitialiser.h"

PassageNiveauContexte *contexte;

/*****************************************************************************
* clignotement des feux routiers
***************************************************************************/


void passage_a_niveau_gerer() {
  /*
  if (situation == ferme) {
    clignote();
  }
    
  if (capteurOuverture.fell()) {
    //moteur_barriere_ouvrir();
  }
      
  if (capteurFermeture.fell()) {
    //moteur_barriere_fermer();
  }
    
  if (situation == encours) {
    //moteur_barriere_manoeuvrer();
  }
  */
}


void setup()
{
  Serial.begin(115200);

  contexte  = new PassageNiveauContexte(new PassageNiveauEtatInitialiser());
} 
 
void loop()
{    
    delay(100);
    capteurOuverture.update();
    capteurFermeture.update();
    contexte->TraiterFonctionDuContexte();
}
