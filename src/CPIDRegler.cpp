/* 
 * File:   CPIDRegler.cpp
 * Author: sascha
 * 
 * Created on 6. September 2012, 09:39
 */

#include "CPIDRegler.h"

CPIDRegler::CPIDRegler(CSensor * pSesnor, uint8_t iSensorChannle, CActor * pActor, uint8_t iActorChannle)
{
    m_pSensor           = pSesnor;
    m_iSensorChannle    = iSensorChannle;
    m_pActor            = pActor;
    m_iActorChannle     = iActorChannle;
}

CPIDRegler::~CPIDRegler()
{
    
}

void CPIDRegler::setSoll(float soll)
{
    m_soll = soll;
}

void CPIDRegler::setKp(float Kp)
{
    m_Kd = Kp;
}

void CPIDRegler::setKi(float Ki)
{
    m_Ki = Ki;
}

void CPIDRegler::setKd(float Kd)
{
    m_Kd = Kd;
}

float CPIDRegler::getKp()
{
    return m_Kp;
}

float CPIDRegler::getKi()
{
    return m_Ki;
}

float CPIDRegler::getKd()
{
    return m_Kd;
}

void CPIDRegler::start()
{
        m_PIDReglerThread = boost::thread(&CPIDRegler::run, this);
}

void CPIDRegler::stop()
{
    m_bStop = true;
    m_PIDReglerThread.join();
}

void CPIDRegler::kill()
{
    m_PIDReglerThread.interrupt();
    m_PIDReglerThread.join();
}

void CPIDRegler::run()
{
    try
    {
        while (!m_bStop)
        {
            m_e = m_soll - m_pSensor(m_iSensorChannle);
            m_esum = m_esum + m_e;
            m_pActor(m_Kp * m_e + m_Ki * Ta * m_esum + m_Kd * (m_e - m_ealt) / Ta, m_iActorChannle);
            m_ealt = m_e;
        }
    }
    catch (boost::thread_interrupted&)
    {

    }
}