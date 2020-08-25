/*****************************************************************************
* Gestion d'une barriere dans un seul sens de direction par
* 2 capteurs un pour l'entree du train et l'autre pour la sortie, ILS, detecteur de consommation ou autre
* 2 servos de type SG90 mis tete beche sur leur cote afin de limiter leur emprise
* ce qui fait que quand un servo tourne dans un sens l'autre tourne dans l'autre sens
* et 2 feux routiers qui clignotent
***************************************************************************/
#include "Feu.h"
#include "Clignoter.h"
#include "Barriere.h"

#define PIN_SERVO_DROIT A2  
#define PIN_SERVO_GAUCHE A3

// a regler en fonction des servos

#define VITESSE_SERVO 80
#define ANGLE_FERMETURE 1300
#define ANGLE_OUVERTURE 1900
#define PAS_ANGULAIRE 60


#define PIN_FEU_DROIT 4
#define PIN_FEU_GAUCHE 5


/******************************************************************************
* les capteurs
********************************************************************************/
#include <Bounce2.h>
  

#include "PassageNiveauContexte.h"
#include "PassageNiveauEtatInitialiserCapteurs.h"

PassageNiveauContexte *contexte;


void setup()
{
  Serial.begin(115200);

  int nombreFeux = 2;
  Feu ** feux = (Feu **) malloc(sizeof(Feu *) * nombreFeux);
  
  feux[0] = new Feu(PIN_FEU_GAUCHE);
  feux[1] = new Feu(PIN_FEU_DROIT);

  Clignoter * clignoter = new Clignoter();

  Barriere * barriereGauche = new Barriere(PIN_SERVO_GAUCHE, ANGLE_FERMETURE, ANGLE_OUVERTURE, PAS_ANGULAIRE, VITESSE_SERVO, false);
  Barriere * barriereDroite = new Barriere(PIN_SERVO_DROIT, ANGLE_FERMETURE, ANGLE_OUVERTURE, PAS_ANGULAIRE, VITESSE_SERVO, false);

  
  Bounce capteurOuverture;
  Bounce capteurFermeture;
  
  contexte  = new PassageNiveauContexte(new PassageNiveauEtatInitialiserCapteurs(), feux, nombreFeux, clignoter, barriereGauche, barriereDroite, capteurOuverture, capteurFermeture);
} 
 
void loop()
{    
    delay(100);
    contexte->capteurOuverture.update();
    contexte->capteurFermeture.update();

    
    contexte->TraiterFonctionDuContexte();
}
