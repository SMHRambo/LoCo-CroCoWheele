#include "../include/CBMA180.h"

CBMA180::CBMA180(CI2C pI2C)
{

}

CBMA180::~CBMA180()
{

}

uint16_t CBMA180::getAccXRaw()
{
    uint16_t iAccX = 0;
    
    m_BMA180Mutex.lock();
    
    iAccX = m_iAccX;
    
    m_BMA180Mutex.unlock();
    
    return iAccX;
}

uint16_t CBMA180::getAccYRaw()
{
    uint16_t iAccY = 0;
    
    m_BMA180Mutex.lock();
    
    iAccY = m_iAccY;
    
    m_BMA180Mutex.unlock();
    
    return iAccY;
}

uint16_t CBMA180::getAccZRaw()
{
    uint16_t iAccZ = 0;
    
    m_BMA180Mutex.lock();
    
    iAccZ = m_iAccZ;
    
    m_BMA180Mutex.unlock();
    
    return iAccZ;
}

double CBMA180::getAccX()
{
    double iAccX = 0;
    
    m_BMA180Mutex.lock();
    
    iAccX = m_iAccX;
    
    m_BMA180Mutex.unlock();
    
    return iAccX;
}

double CBMA180::getAccY()
{
    double iAccY = 0;
    
    m_BMA180Mutex.lock();
    
    iAccY = m_iAccY;
    
    m_BMA180Mutex.unlock();
    
    return iAccY;
}

double CBMA180::getAccZ()
{
    double iAccZ = 0;
    
    m_BMA180Mutex.lock();
    
    iAccZ = m_iAccZ;
    
    m_BMA180Mutex.unlock();
    
    return iAccZ;
}

double CBMA180::getAccAlpha()
{
    double iAlpha = 0;
    
    m_BMA180Mutex.lock();
    
    iAlpha = m_iAccX / sqrt(m_iAccX^2 + m_iAccY^2 + m_iAccZ^2);
    
    m_BMA180Mutex.unlock();
    
    return iAlpha;
}

double CBMA180::getAccBeta()
{
    double iBeta = 0;
    
    m_BMA180Mutex.lock();
    
    iBeta = m_iAccY / sqrt(m_iAccX^2 + m_iAccY^2 + m_iAccZ^2);
    
    m_BMA180Mutex.unlock();
    
    return iBeta;
}

double CBMA180::getAccGamma()
{
    double iGamma = 0;
    
    m_BMA180Mutex.lock();
    
    iGamma = m_iAccZ / sqrt(m_iAccX^2 + m_iAccY^2 + m_iAccZ^2);
    
    m_BMA180Mutex.unlock();
    
    return iGamma;
}

CVector CBMA180::getVector()
{

}

uint16_t CBMA180::getAccXRawPerI2C()
{

}

uint16_t CBMA180::getAccYRawPerI2C()
{

}

uint16_t CBMA180::getAccZRawPerI2C()
{

}

double CBMA180::getAccXPerI2C()
{

}

double CBMA180::getAccYPerI2C()
{

}

double CBMA180::getAccZPerI2C()
{

}

double CBMA180::getAccAlphaPerI2C()
{

}

double CBMA180::getAccBetaPerI2C()
{

}

double CBMA180::getAccGammaPerI2C()
{

}

CVector CBMA180::getVectorPerI2C()
{

}

void CBMA180::start()
{

}

void CBMA180::stop()
{

}

void CBMA180::run()
{

}
