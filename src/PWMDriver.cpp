#include "../include/PWMDriver.h"

PWMDriver::PWMDriver()(CI2C * pI2C, uint8_t iAddress)
{
    m_pI2C = pI2C;
    m_iAddress = iAddress;
}

PWMDriver::~PWMDriver() {
}

void setPWM(uint8_t iChannle, uint16_t iDutyCycle)
{
    std::vector<uint8_t> viData;

    viData.push_back(iChannel * 2);
    viData.push_back(*((uint8_t *)iDutyCycle[0]));
    viData.push_back(*((uint8_t *)iDutyCycle[1]));

    m_pI2C->lock();
    m_pI2C->writeI2C(m_iAddress, viData);
    m_pI2C->unlock();   
}

void setPeriod(uint16_t iPeriodTime)
{
    std::vector<uint8_t> viData;

    viData.push_back(32);
    viData.push_back(((uint8_t *)&iPeriodTime)[0]);
    viData.push_back(((uint8_t *)&iPeriodTime)[1]);

    m_pI2C->lock();
    m_pI2C->writeI2C(m_iAddress, viData);
    m_pI2C->unlock();       
}


uint16_t getPWM(uint8_t iChannle)
{
    std::vector<uint8_t> viData;
    uint16_t iDutyCycle = 0;
    uint8_t * piDutyCycle = (uint8_t*) & iDutyCycle;

    viData.push_back(iChannle * 2);

    m_pI2C->lock();
    m_pI2C->writeI2C(m_iAddress, viData);
    if (m_pI2C->readI2C(m_iAddress, viData, 2))
    {
        piDutyCycle[0] = viData.at(0);
        piDutyCycle[1] = viData.at(1);
    }
    
    m_pI2C->unlock();

    return iDutyCycle;
}

uint16_t getPeriod()
{
    std::vector<uint8_t> viData;
    uint16_t iPeriodTime = 0;
    uint8_t * piPeriodTime = (uint8_t*) & iPeriodTime;

    viData.push_back(32);

    m_pI2C->lock();
    m_pI2C->writeI2C(m_iAddress, viData);
    if (m_pI2C->readI2C(m_iAddress, viData, 2))
    {
        piPeriodTime[0] = viData.at(0);
        piPeriodTime[1] = viData.at(1);
    }
    
    m_pI2C->unlock();

    return iPeriodTime;
}

