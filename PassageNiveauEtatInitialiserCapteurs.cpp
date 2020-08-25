#include <Arduino.h>
#include <Bounce2.h>

#include "PassageNiveauContexte.h"
#include "PassageNiveauEtatInitialiserCapteurs.h"
#include "PassageNiveauEtatAmorcerOuverture.h"

#define PIN_CAPTEUR_OUVRE 2  
#define PIN_CAPTEUR_FERME 3  
#define INTERVAL 50

void PassageNiveauEtatInitialiserCapteurs::TraiterEtat() {
    Serial.println("PassageNiveauEtatInitialiserCapteurs");

    pinMode(PIN_CAPTEUR_OUVRE,INPUT_PULLUP);
    this->_contexte->capteurOuverture.attach(PIN_CAPTEUR_OUVRE);
    this->_contexte->capteurOuverture.interval(INTERVAL);
    this->_contexte->capteurOuverture.update();
    
    pinMode(PIN_CAPTEUR_FERME, INPUT_PULLUP);
    this->_contexte->capteurFermeture.attach(PIN_CAPTEUR_FERME);
    this->_contexte->capteurFermeture.interval(INTERVAL);
    this->_contexte->capteurFermeture.update();

    int positionBarriereGauche = this->_contexte->barriereGauche->LirePositionBarriere();
    int positionBarriereDroite = this->_contexte->barriereDroite->LirePositionBarriere();

    Serial.print("PositionBarriereGauche: ");
    Serial.print(positionBarriereGauche);
    Serial.print(" PositionBarriereDroite: ");
    Serial.println(positionBarriereDroite);
    
    this->_contexte->TransiterVers(new PassageNiveauEtatAmorcerOuverture());
}
