#include "../include/PIDRegler.h"

PIDRegler::PIDRegler(CSensor * pSensor, uint8_t iSensorChannle, CActor * pActor, uint8_t iActorChannle)
{
    m_pSensor = pSensor;
    m_pActor = pActor;
    m_iSensorChannle = iSensorChannle;
    m_iActorChannle = iActorChannle;
}

PIDRegler::~PIDRegler()
{
    
}

PIDRegler::run()
{
        m_e = w - x;
        m_esum = m_esum + m_e;
        y = m_Kp * m_e + m_Ki * Ta * m_esum + m_Kd * (m_e – m_ealt)/Ta;
        m_ealt = m_e;
}
