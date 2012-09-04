#ifndef PIDREGLER_H
#define	PIDREGLER_H

#include <stdint.h>
#include <boost/thread.hpp>

class PIDRegler
{
public:
    PIDRegler();
    virtual ~PIDRegler();
    
    start();
    stop();
    kill();
    run();
private:
    float           m_e = 0;                    //Regelabweichung
    float           m_esum = 0;                 //Summe aller Regelabweichungen
    float           m_ealt = 0;                 //letzte Regelabweichung
    float           m_Kp = 0;                   //proportionaler Verstärkungsfaktor
    float           m_Ki = 0;                   //integraler Verstärkungsfaktor
    float           m_Kd = 0;                   //differentialer Verstärkungsfaktor
    CSensor*        m_pSensor = 0;              //Pointer auf den Sensors
    uint8_t         m_iSensorChannle = 0;       //Zu benutzende Funktion des Sensors
    CActor*         m_pActor = 0;               //Pointer auf den Actors
    uint8_t         m_iActorChannle = 0;        //Zu benutzende Funktion des Actors

};

#endif	/* PIDREGLER_H */

