#ifndef MOTEUR_BARRIERE_H
#define MOTEUR_BARRIERE_H

#include <Servo.h>

/***************************************************************/
/* MAPPINGS DES PINS DE L'ARDUINO                              */
/*   à régler en fonction du type de la carte                  */
/***************************************************************/

#define PIN_SERVO_DROIT A2  
#define PIN_SERVO_GAUCHE A3

/***************************************************************/
/***************************************************************/
/***************************************************************/

/***************************************************************/
/* CONSTANTES POUR LA GESTION DES SERVOMOTEURS                 */
/*   à régler en fonction du type des SERVOS;                  */
/*   cette librairie est prévue pour un même                   */
/*   type de servo pour pour les deux barrières;               */
/***************************************************************/

#define VITESSE_SERVO 80
#define ANGLE_FERMETURE 1300
#define ANGLE_OUVERTURE 1900
#define PAS_ANGULAIRE 20

enum mode {montee,descente,arret};
enum etat {ouvert, ferme, encours};

/***************************************************************/
/***************************************************************/
/***************************************************************/

/***************************************************************/
/* VARIABLES DE GESTION DE MOUVEMENTS DES BARRIERES .          */
/***************************************************************/

extern int angleFerme;                     // angle de fermeture
extern int angleOuvre;                     // angle pour l'ouverture
extern int angleDroit;                                       // angle actuel du servo 1
extern int angleGauche;                                      // angle actuel du servo 2
extern int pasServo;                         // pas angulaire
extern bool actif;                                   // etat de la manoeuvre                                      
extern unsigned long timerServo;                             // timer pour le servo
extern int duree;                            // vitesse des servos            
extern Servo servoDroit;                                     // servo de la premiere barriere
extern Servo servoGauche;                                    // servo de la seconde barriere

extern mode sens;                                    // sens du mouvement de la barriere
extern etat situation;                              // situation de la barriere

/***************************************************************/
/***************************************************************/
/***************************************************************/

/***************************************************************/
/* FONCTIONS DE GESTION DE MOUVEMENTS DES BARRIERES            */
/***************************************************************/

void moteur_barriere_initialiser();

void moteur_barriere_ouverture();

void moteur_barriere_fermeture();

void moteur_barriere_manoeuvre();

/***************************************************************/
/***************************************************************/
/***************************************************************/


#endif
