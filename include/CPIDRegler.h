/* 
 * File:   CPIDRegler.h
 * Author: sascha
 *
 * Created on 6. September 2012, 09:39
 */

#ifndef CPIDREGLER_H
#define	CPIDREGLER_H

#include <stdint.h>
#include <boost/thread.hpp>

#include "CActor.h"
#include "CSensor.h"

class CPIDRegler
{
    public:
        CPIDRegler(CSensor * pSesnor, uint8_t iSensorChannle, CActor * pActor, uint8_t iActorChannle);
        virtual ~CPIDRegler();
        
        void setSoll(float soll);
        
        void setKp(float Kp);
        void setKi(float Ki);
        void setKd(float Kd);
        void setTime(uint16_t iTime);
        
        float getKp();
        float getKi();
        float getKd();        
        uint16_t getTime();
        
        void start();
        void stop();
        void kill();
        void run();
        
    private:
        boost::recursive_mutex  m_PIDReglerMutex;
        boost::thread           m_PIDReglerThread;
        bool                    m_bStop;
        float                   m_soll;
        float                   m_e;                    //Regelabweichung
        float                   m_esum;                 //Summe aller Regelabweichungen
        float                   m_ealt;                 //letzte Regelabweichung
        float                   m_Kp;                   //proportionaler Verstärkungsfaktor
        float                   m_Ki;                   //integraler Verstärkungsfaktor
        float                   m_Kd;                   //differentialer Verstärkungsfaktor
        uint16_t                m_iTime;
        uint16_t                m_iTimeNow;
        CSensor*                m_pSensor;              //Pointer auf den Sensors
        uint8_t                 m_iSensorChannle;       //Zu benutzende Funktion des Sensors
        CActor*                 m_pActor;               //Pointer auf den Actors
        uint8_t                 m_iActorChannle;        //Zu benutzende Funktion des Actors

};

#endif	/* CPIDREGLER_H */

