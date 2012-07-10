#include "../include/CITG3200.h"

CITG3200::CITG3200()
{

}

CITG3200::~CITG3200()
{

}


uint16_t CITG3200::getGyroXRaw()
{
    uint16_t iGyroX = 0;
    
    m_ITG3200Mutex.lock();
    
    iGyroX = m_iGyroX;
    
    m_ITG3200Mutex.unlock();
    
    return iGyroX;
}

uint16_t CITG3200::getGyroYRaw()
{
    uint16_t iGyroY = 0;
    
    m_ITG3200Mutex.lock();
    
    iGyroY = m_iGyroY;
    
    m_ITG3200Mutex.unlock();
    
    return iGyroY;
}

uint16_t CITG3200::getGyroZRaw()
{
    uint16_t iGyroZ = 0;
    
    m_ITG3200Mutex.lock();
    
    iGyroZ = m_iGyroZ;
    
    m_ITG3200Mutex.unlock();
    
    return iGyroZ;
}

double CITG3200::getGyroX()
{
    double iGyroX = 0;
    
    m_ITG3200Mutex.lock();
    
    iGyroX = m_iGyroX;
    
    m_ITG3200Mutex.unlock();
    
    return iGyroX;
}

double CITG3200::getGyroY()
{
    double iGyroY = 0;
    
    m_ITG3200Mutex.lock();
    
    iGyroY = m_iGyroY;
    
    m_ITG3200Mutex.unlock();
    
    return iGyroY;
}

double CITG3200::getGyroZ()
{
    double iGyroZ = 0;
    
    m_ITG3200Mutex.lock();
    
    iGyroZ = m_iGyroZ;
    
    m_ITG3200Mutex.unlock();
    
    return iGyroZ;
}


double CITG3200::getGyroAlpha()
{
    double iAlpha = 0;
    
    m_ITG3200Mutex.lock();
    
    iAlpha = m_iGyroX / sqrt(m_iGyroX^2 + m_iGyroY^2 + m_iGyroZ^2);
    
    m_ITG3200Mutex.unlock();
    
    return iAlpha;
}

double CITG3200::getGyroBeta()
{
    double iBeta = 0;
    
    m_ITG3200Mutex.lock();
    
    iBeta = m_iGyroY / sqrt(m_iGyroX^2 + m_iGyroY^2 + m_iGyroZ^2);
    
    m_ITG3200Mutex.unlock();
    
    return iBeta;
}

double CITG3200::getGyroGamma()
{
    double iGamma = 0;
    
    m_ITG3200Mutex.lock();
    
    iGamma = m_iGyroZ / sqrt(m_iGyroX^2 + m_iGyroY^2 + m_iGyroZ^2);
    
    m_ITG3200Mutex.unlock();
    
    return iGamma;
}


CVector CITG3200::getGyroVector()
{

}


uint16_t CITG3200::getGyroXRawPerI2C()
{

}

uint16_t CITG3200::getGyroYRawPerI2C()
{

}

uint16_t CITG3200::getGyroZRawPerI2C()
{

}


double CITG3200::getGyroXPerI2C()
{

}

double CITG3200::getGyroYPerI2C()
{

}

double CITG3200::getGyroZPerI2C()
{

}


double CITG3200::getGyroAlphaPerI2C()
{

}

double CITG3200::getGyroBetaPerI2C()
{

}

double CITG3200::getGyroGammaPerI2C()
{

}


CVector CITG3200::getGyroVectorPerI2C()
{

}


void CITG3200::start()
{

}

void CITG3200::stop()
{

}

void CITG3200::run()
{

}
