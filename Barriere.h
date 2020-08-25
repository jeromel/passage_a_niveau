#ifndef BARRIERE_H
#define BARRIERE_H

#include <Arduino.h>
#include <Servo.h>

class Barriere {
    private:
        int _numeroPinServoMoteurBarriere;

        Servo _servoMoteurBarriere;

        int _angleMin;
        int _angleMax;

        int _angleActuel;

        int _pasServo;

        unsigned long _tempoServoMoteur;
        unsigned long _vitesseServoMoteur;

        bool _sensInverse;

        bool ManoeuvrerDeMinVersMax();

        bool ManoeuvrerDeMaxVersMin();

    public:
        Barriere(int numeroPinServoMoteurBarriere, int angleMin, int angleMax, int pasServo, unsigned long vitesseServoMoteur, bool sensInverse = false) {
            this->_numeroPinServoMoteurBarriere = numeroPinServoMoteurBarriere;

            this->_angleMin = angleMin;
            this->_angleMax = angleMax;

            this->_pasServo = pasServo;

            this->_sensInverse = sensInverse;

            this->_tempoServoMoteur = millis();
            this->_vitesseServoMoteur = millis();

            this->_vitesseServoMoteur = vitesseServoMoteur;

            this->AmorcerOuverture();
        }

        int LirePositionBarriere();
        
        void AmorcerOuverture();

        void AmorcerFermeture();
        
        bool ManoeuvrerOuvrir();

        bool ManoeuvrerFermer();
};

#endif
