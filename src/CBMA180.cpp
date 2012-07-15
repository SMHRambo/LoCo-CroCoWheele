#include "../include/CBMA180.h"

CBMA180::CBMA180(CI2C * pI2C, uint8_t iAddress)
{
    m_pI2C = pI2C;
    m_iAddress = iAddress;
    m_bStop = false;
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
    std::vector<uint8> viData;
    viData.push_back(0x);
    
    m_pI2C->lock();
    m_pI2C->writeI2C(m_iAddress,);
    m_pI2C->readI2C(m_iAddress,viData,2);
    m_pI2C->lock();
    
    
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
        m_BMA180Thread = boost::thread(&CBMA180::run, this);
}

void CBMA180::stop()
{
    m_Stop = true;
    m_BMA180Thread.join();
}

void CBMA180::kill()
{
    m_BMA180Thread.interrupt();
    m_BMA180Thread.join();
}

void CBMA180::run()
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
