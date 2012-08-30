#include "../include/CITG3200.h"

CITG3200::CITG3200(CI2C * pI2C, uint8_t iAddress)
{
    m_pI2C = pI2C;
    m_iAddress = iAddress;
    m_bStop = false;
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
    m_ITG3200Thread = boost::thread(&CITG3200::run, this);
}

void CITG3200::stop()
{
    m_bStop = true;
    m_ITG3200Thread.join();
}

void CITG3200::kill()
{
    m_ITG3200Thread.interrupt();
    m_ITG3200Thread.join();
}

void CITG3200::run()
{
    try
    {
        while(!m_bStop)
        {
            
        }
    }
    catch(boost::thread_interrupted&)
    {
        
    }
}

int8_t CITG3200::getValue(int16_t &iValue, unint8_t iChannle);
{
    switch(iChannle)
    {
        case 0:
            iValue = m_iGyroX;
            break;
        case 1:
            iValue = m_iGyroY;
            break;
        case 2:
            iValue = m_iGyroZ;
            break;
        default:
            iValue = 0;
            return 0;
            break;
    }

    return 1;
}