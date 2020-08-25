#include "Arduino.h"

#include "Barriere.h"

bool Barriere::ManoeuvrerDeMaxVersMin() {
  bool manoeuvreTerminee = false;
  
  if (this->_angleActuel > this->_angleMin) {  
    this->_angleActuel = this->_angleActuel - this->_pasServo;
    
    this->_servoMoteurBarriere.writeMicroseconds(this->_angleActuel);
  }
  else {
    this->_servoMoteurBarriere.detach();
    manoeuvreTerminee = true;
  }

  return manoeuvreTerminee;
}

bool Barriere::ManoeuvrerDeMinVersMax() {
  bool manoeuvreTerminee = false;
  
  if (this->_angleActuel < this->_angleMax) {  
    this->_angleActuel = this->_angleActuel + this->_pasServo;
    
    this->_servoMoteurBarriere.writeMicroseconds(this->_angleActuel);
  }
  else {
    this->_servoMoteurBarriere.detach();
    manoeuvreTerminee = true;
  }

  return manoeuvreTerminee;
}

void Barriere::AmorcerFermeture() {
    this->_servoMoteurBarriere.attach(this->_numeroPinServoMoteurBarriere);

    if (true == this->_sensInverse) {
      this->_angleActuel = this->_angleMin;
    }
    else {
     this->_angleActuel = this->_angleMax; 
    }
 
    this->_tempoServoMoteur = millis();

    Serial.print("AmorcerFermeture (Angle actuel: ");
    Serial.print(this->_angleActuel);
    Serial.print(") (SensInverse: ");
    Serial.print(this->_sensInverse);
    Serial.println(")");
}

void Barriere::AmorcerOuverture() {
    this->_servoMoteurBarriere.attach(this->_numeroPinServoMoteurBarriere);

    if (true == this->_sensInverse) {
      this->_angleActuel = this->_angleMax;
    }
    else {
      this->_angleActuel = this->_angleMin;
    }

    this->_tempoServoMoteur = millis();

    Serial.print("AmorcerOuverture (Angle actuel: ");
    Serial.print(this->_angleActuel);
    Serial.print(") (SensInverse: ");
    Serial.print(this->_sensInverse);
    Serial.println(")");
}

bool Barriere::ManoeuvrerFermer() {
    bool manoeuvreTerminee = false;
  
    if ((this->_tempoServoMoteur + this->_vitesseServoMoteur) < millis()) {
        if (true == this->_sensInverse) {
          manoeuvreTerminee = this->ManoeuvrerDeMinVersMax();
        }
        else {
          manoeuvreTerminee = this->ManoeuvrerDeMaxVersMin();
        }
    }

    Serial.print("ManoeuvrerFermer (Terminee : ");
    Serial.print(manoeuvreTerminee);
    Serial.print(") (Angle actuel: ");
    Serial.print(this->_angleActuel);
    Serial.print(") (SensInverse: ");
    Serial.print(this->_sensInverse);
    Serial.println(")");
    
    return manoeuvreTerminee;
}

bool Barriere::ManoeuvrerOuvrir() {
    bool manoeuvreTerminee = false;
    
    if ((this->_tempoServoMoteur + this->_vitesseServoMoteur) < millis()) {
        if (true == this->_sensInverse) {
          manoeuvreTerminee = this->ManoeuvrerDeMaxVersMin();
        }
        else {
          manoeuvreTerminee = this->ManoeuvrerDeMinVersMax();
        }
    }

    Serial.print("ManoeuvrerOuvrir (Terminee : ");
    Serial.print(manoeuvreTerminee);
    Serial.print(") (Angle actuel: ");
    Serial.print(this->_angleActuel);
    Serial.print(") (SensInverse: ");
    Serial.print(this->_sensInverse);
    Serial.println(")");
    
    return manoeuvreTerminee;
}

int Barriere::LirePositionBarriere() {
  int positionBarriere = this->_servoMoteurBarriere.read(); 

  return positionBarriere;
}
