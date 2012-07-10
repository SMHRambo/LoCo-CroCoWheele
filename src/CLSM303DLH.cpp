#include "../include/CLSM303DLH.h"

CLSM303DLH::CLSM303DLH(CI2C pI2C)
{

}

CLSM303DLH::~CLSM303DLH()
{

}

uint16_t CLSM303DLH::getAccXRaw()
{
    uint16_t iAccX = 0;
    
    m_LSM303DLHMutex.lock();
    
    iAccX = m_iAccX;
    
    m_LSM303DLHMutex.unlock();
    
    return iAccX;
}

uint16_t CLSM303DLH::getAccYRaw()
{
    uint16_t iAccY = 0;
    
    m_LSM303DLHMutex.lock();
    
    iAccY = m_iAccY;
    
    m_LSM303DLHMutex.unlock();
    
    return iAccY;
}

uint16_t CLSM303DLH::getAccZRaw()
{
    uint16_t iAccZ = 0;
    
    m_LSM303DLHMutex.lock();
    
    iAccZ = m_iAccZ;
    
    m_LSM303DLHMutex.unlock();
    
    return iAccZ;
}

double CLSM303DLH::getAccX()
{
    double iAccX = 0;
    
    m_LSM303DLHMutex.lock();
    
    iAccX = m_iAccX;
    
    m_LSM303DLHMutex.unlock();
    
    return iAccX;
}

double CLSM303DLH::getAccY()
{
    double iAccY = 0;
    
    m_LSM303DLHMutex.lock();
    
    iAccY = m_iAccY;
    
    m_LSM303DLHMutex.unlock();
    
    return iAccY;
}

double CLSM303DLH::getAccZ()
{
    double iAccZ = 0;
    
    m_LSM303DLHMutex.lock();
    
    iAccZ = m_iAccZ;
    
    m_LSM303DLHMutex.unlock();
    
    return iAccZ;
}

double CLSM303DLH::getAccAlpha()
{
    double iAlpha = 0;
    
    m_LSM303DLHMutex.lock();
    
    iAlpha = m_iAccX / sqrt(m_iAccX^2 + m_iAccY^2 + m_iAccZ^2);
    
    m_LSM303DLHMutex.unlock();
    
    return iAlpha;
}

double CLSM303DLH::getAccBeta()
{
    double iBeta = 0;
    
    m_LSM303DLHMutex.lock();
    
    iBeta = m_iAccY / sqrt(m_iAccX^2 + m_iAccY^2 + m_iAccZ^2);
    
    m_LSM303DLHMutex.unlock();
    
    return iBeta;
}

double CLSM303DLH::getAccGamma()
{
    double iGamma = 0;
    
    m_LSM303DLHMutex.lock();
    
    iGamma = m_iAccZ / sqrt(m_iAccX^2 + m_iAccY^2 + m_iAccZ^2);
    
    m_LSM303DLHMutex.unlock();
    
    return iGamma;
}

CVector CLSM303DLH::getAccVector()
{

}

uint16_t CLSM303DLH::getAccXRawPerI2C()
{

}

uint16_t CLSM303DLH::getAccYRawPerI2C()
{

}

uint16_t CLSM303DLH::getAccZRawPerI2C()
{

}

double CLSM303DLH::getAccXPerI2C()
{

}

double CLSM303DLH::getAccYPerI2C()
{

}

double CLSM303DLH::getAccZPerI2C()
{

}

double CLSM303DLH::getAccAlphaPerI2C()
{

}

double CLSM303DLH::getAccBetaPerI2C()
{

}

double CLSM303DLH::getAccGammaPerI2C()
{

}

CVector CLSM303DLH::getAccVectorPerI2C()
{

}

uint16_t CLSM303DLH::getMagXRaw()
{
    uint16_t iMagX = 0;
    
    m_LSM303DLHMutex.lock();
    
    iMagX = m_iMagX;
    
    m_LSM303DLHMutex.unlock();
    
    return iMagX;
}

uint16_t CLSM303DLH::getMagYRaw()
{
    uint16_t iMagY = 0;
    
    m_LSM303DLHMutex.lock();
    
    iMagY = m_iMagY;
    
    m_LSM303DLHMutex.unlock();
    
    return iMagY;
}

uint16_t CLSM303DLH::getMagZRaw()
{
    uint16_t iMagZ = 0;
    
    m_LSM303DLHMutex.lock();
    
    iMagZ = m_iMagZ;
    
    m_LSM303DLHMutex.unlock();
    
    return iMagZ;
}

double CLSM303DLH::getMagX()
{
    double iMagX = 0;
    
    m_LSM303DLHMutex.lock();
    
    iMagX = m_iMagX;
    
    m_LSM303DLHMutex.unlock();
    
    return iMagX;
}

double CLSM303DLH::getMagY()
{
    uint16_t iMagY = 0;
    
    m_LSM303DLHMutex.lock();
    
    iMagY = m_iMagY;
    
    m_LSM303DLHMutex.unlock();
    
    return iMagY;
}

double CLSM303DLH::getMagZ()
{
    uint16_t iMagZ = 0;
    
    m_LSM303DLHMutex.lock();
    
    iMagZ = m_iMagZ;
    
    m_LSM303DLHMutex.unlock();
    
    return iMagZ;
}

double CLSM303DLH::getMagAlpha()
{
    double iAlpha = 0;
    
    m_LSM303DLHMutex.lock();
    
    iAlpha = m_iMagX / sqrt(m_iMagX^2 + m_iMagY^2 + m_iMagZ^2);
    
    m_LSM303DLHMutex.unlock();
    
    return iAlpha;
}

double CLSM303DLH::getMagBeta()
{
    double iBeta = 0;
    
    m_LSM303DLHMutex.lock();
    
    iBeta = m_iMagY / sqrt(m_iMagX^2 + m_iMagY^2 + m_iMagZ^2);
    
    m_LSM303DLHMutex.unlock();
    
    return iBeta;
}

double CLSM303DLH::getMagGamma()
{
    double iGamma = 0;
    
    m_LSM303DLHMutex.lock();
    
    iGamma = m_iMagZ / sqrt(m_iMagX^2 + m_iMagY^2 + m_iMagZ^2);
    
    m_LSM303DLHMutex.unlock();
    
    return iGamma;
}

CVector CLSM303DLH::getMagVector()
{

}

uint16_t CLSM303DLH::getMagXRawPerI2C()
{

}

uint16_t CLSM303DLH::getMagYRawPerI2C()
{

}

uint16_t CLSM303DLH::getMagZRawPerI2C()
{

}

double CLSM303DLH::getMagXPerI2C()
{

}

double CLSM303DLH::getMagYPerI2C()
{

}

double CLSM303DLH::getMagZPerI2C()
{

}

double CLSM303DLH::getMagAlphaPerI2C()
{

}

double CLSM303DLH::getMagBetaPerI2C()
{

}

double CLSM303DLH::getMagGammaPerI2C()
{

}

CVector CLSM303DLH::getMagVectorPerI2C()
{

}

void CLSM303DLH::start()
{

}

void CLSM303DLH::stop()
{

}

void CLSM303DLH::run()
{

}