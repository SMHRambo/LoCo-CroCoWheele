#include "../include/CBMA180.h"

// <editor-fold defaultstate="collapsed" desc=" CBMA180::CBMA180(CI2C * pI2C, uint8_t iAddress) ">

CBMA180::CBMA180(CI2C * pI2C, uint8_t iAddress)
{
    m_pI2C = pI2C;
    m_iAddress = iAddress;
    m_bStop = false;
}

// </editor-fold>

CBMA180::~CBMA180()
{

}

// <editor-fold defaultstate="collapsed" desc=" uint16_t CBMA180::getAccXRaw ">

uint16_t CBMA180::getAccXRaw()
{
    uint16_t iAccX = 0;

    m_BMA180Mutex.lock();

    iAccX = m_iAccX;

    m_BMA180Mutex.unlock();

    return iAccX;
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" uint16_t CBMA180::getAccYRaw ">

uint16_t CBMA180::getAccYRaw()
{
    uint16_t iAccY = 0;

    m_BMA180Mutex.lock();

    iAccY = m_iAccY;

    m_BMA180Mutex.unlock();

    return iAccY;
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" uint16_t CBMA180::getAccZRaw ">

uint16_t CBMA180::getAccZRaw()
{
    uint16_t iAccZ = 0;

    m_BMA180Mutex.lock();

    iAccZ = m_iAccZ;

    m_BMA180Mutex.unlock();

    return iAccZ;
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" double CBMA180::getAccX() ">

double CBMA180::getAccX()
{
    double iAccX = 0;

    m_BMA180Mutex.lock();

    iAccX = m_iAccX;

    m_BMA180Mutex.unlock();

    return iAccX;
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" double CBMA180::getAccY() ">

double CBMA180::getAccY()
{
    double iAccY = 0;

    m_BMA180Mutex.lock();

    iAccY = m_iAccY;

    m_BMA180Mutex.unlock();

    return iAccY;
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" double CBMA180::getAccZ() ">

double CBMA180::getAccZ()
{
    double iAccZ = 0;

    m_BMA180Mutex.lock();

    iAccZ = m_iAccZ;

    m_BMA180Mutex.unlock();

    return iAccZ;
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" double CBMA180::getAccAlpha() ">

double CBMA180::getAccAlpha() {
    double iAlpha = 0;

    m_BMA180Mutex.lock();

    iAlpha = m_iAccX / sqrt(m_iAccX^2 + m_iAccY^2 + m_iAccZ^2);

    m_BMA180Mutex.unlock();

    return iAlpha;
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" double CBMA180::getAccBeta() ">

double CBMA180::getAccBeta() {
    double iBeta = 0;

    m_BMA180Mutex.lock();

    iBeta = m_iAccY / sqrt(m_iAccX^2 + m_iAccY^2 + m_iAccZ^2);

    m_BMA180Mutex.unlock();

    return iBeta;
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" double CBMA180::getAccGamma() ">

double CBMA180::getAccGamma() {
    double iGamma = 0;

    m_BMA180Mutex.lock();

    iGamma = m_iAccZ / sqrt(m_iAccX^2 + m_iAccY^2 + m_iAccZ^2);

    m_BMA180Mutex.unlock();

    return iGamma;
}

// </editor-fold>

CVector CBMA180::getVector()
{

}

// <editor-fold defaultstate="collapsed" desc=" uint16_t CBMA180::getAccXRawPerI2C() ">

uint16_t CBMA180::getAccXRawPerI2C()
{
    std::vector<uint8_t> viData;
    uint16_t iX = 0;
    uint8_t * piX = (uint8_t*) & iX;

    viData.push_back(0x06);

    m_pI2C->lock();
    m_pI2C->writeI2C(m_iAddress, viData);
    if (m_pI2C->readI2C(m_iAddress, viData, 2))
    {
        piX[0] = viData.at(0);
        piX[1] = viData.at(1);
    }
    
    m_pI2C->unlock();

    return iX;
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" uint16_t CBMA180::getAccYRawPerI2C( ">

uint16_t CBMA180::getAccYRawPerI2C()
{
    std::vector<uint8_t> viData;
    uint16_t iY = 0;
    uint8_t * piY = (uint8_t*) & iY;

    viData.push_back(0x04);

    m_pI2C->lock();
    m_pI2C->writeI2C(m_iAddress, viData);
    if (m_pI2C->readI2C(m_iAddress, viData, 2))
    {
        piY[0] = viData.at(0);
        piY[1] = viData.at(1);
    }
    m_pI2C->unlock();

    return iY;
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" uint16_t CBMA180::getAccZRawPerI2C() ">

uint16_t CBMA180::getAccZRawPerI2C()
{
    std::vector<uint8_t> viData;
    uint16_t iZ = 0;
    uint8_t * piZ = (uint8_t*) & iZ;

    viData.push_back(0x02);

    m_pI2C->lock();
    m_pI2C->writeI2C(m_iAddress, viData);
    if (m_pI2C->readI2C(m_iAddress, viData, 2))
    {
        piZ[0] = viData.at(0);
        piZ[1] = viData.at(1);
    }
    m_pI2C->unlock();

    return iZ;
}

// </editor-fold>

double CBMA180::getAccXPerI2C()
{
    std::vector<uint8_t>        viData;
    uint16_t                    iX = 0;
    
    viData.push_back(0x06);
    
    m_pI2C->lock();
    m_pI2C->writeI2C(m_iAddress,viData);
    if(m_pI2C->readI2C(m_iAddress,viData,2))
    {
        iX = *((uint16_t *)viData.data());
    }
    m_pI2C->unlock();

    return iX;
}

double CBMA180::getAccYPerI2C()
{
    std::vector<uint8_t>        viData;
    uint16_t                    iY = 0;
    
    viData.push_back(0x04);
    
    m_pI2C->lock();
    m_pI2C->writeI2C(m_iAddress,viData);
    if(m_pI2C->readI2C(m_iAddress,viData,2))
    {
        iY = *((uint16_t *)viData.data());
    }
    m_pI2C->unlock();

    return iY;
}

double CBMA180::getAccZPerI2C()
{
    std::vector<uint8_t>  viData;
    uint16_t            iZ = 0;
    double              dZ = 0;
    
    viData.push_back(0x02);
    
    m_pI2C->lock();
    m_pI2C->writeI2C(m_iAddress,viData);
    if(m_pI2C->readI2C(m_iAddress,viData,2))
    {
        iZ = *((uint16_t *)viData.data());
    }
    m_pI2C->unlock();
    
    iZ = iZ<<(16-2);
    
    dZ = iZ/32765;
    
    dZ = dZ*4;

    return dZ;
}

double CBMA180::getAccAlphaPerI2C()
{
    std::vector<uint8_t> viData;
    viData.push_back(0x02);
    
    m_pI2C->lock();
    m_pI2C->writeI2C(m_iAddress,viData);
    m_pI2C->readI2C(m_iAddress,viData,6);
    m_pI2C->unlock();
}

double CBMA180::getAccBetaPerI2C()
{
    std::vector<uint8_t> viData;
    viData.push_back(0x02);
    
    m_pI2C->lock();
    m_pI2C->writeI2C(m_iAddress,viData);
    m_pI2C->readI2C(m_iAddress,viData,6);
    m_pI2C->unlock();
}

double CBMA180::getAccGammaPerI2C()
{
    std::vector<uint8_t> viData;
    viData.push_back(0x02);
    
    m_pI2C->lock();
    m_pI2C->writeI2C(m_iAddress,viData);
    m_pI2C->readI2C(m_iAddress,viData,6);
    m_pI2C->unlock();
}

CVector CBMA180::getVectorPerI2C()
{
    std::vector<uint8_t> viData;
    viData.push_back(0x02);
    
    m_pI2C->lock();
    m_pI2C->writeI2C(m_iAddress,viData);
    m_pI2C->readI2C(m_iAddress,viData,6);
    m_pI2C->unlock();
}

// <editor-fold defaultstate="collapsed" desc=" void CBMA180::start() ">

void CBMA180::start()
{
    m_BMA180Thread = boost::thread(&CBMA180::run, this);
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" void CBMA180::stop() ">

void CBMA180::stop()
{
    m_bStop = true;
    m_BMA180Thread.join();
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" void CBMA180::kill() ">

void CBMA180::kill()
{
    m_BMA180Thread.interrupt();
    m_BMA180Thread.join();
}

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc=" void CBMA180::run() ">

void CBMA180::run()
{
    try
    {
        std::vector<uint8_t> viDataIN;
        std::vector<uint8_t> viDataOUT;
        viDataOUT.push_back(0x02);
        
        while (!m_bStop)
        {
            m_pI2C->lock();
            m_pI2C->writeI2C(m_iAddress, viDataOUT);
            if (m_pI2C->readI2C(m_iAddress, viDataIN, 6))
            {
                m_iAccX = *((int16_t *)&viDataIN.at(4));
                m_iAccY = *((int16_t *)&viDataIN.at(2));
                m_iAccZ = *((int16_t *)&viDataIN.at(0));
            }
            m_pI2C->unlock();
        }
    }
    catch (boost::thread_interrupted&)
    {

    }
}

// </editor-fold>

int8_t CBMA180::getValue(int16_t &iValue, unint8_t iChannle);
{
    switch(iChannle)
    {
        case 0:
            iValue = m_iAccX;
            break;
        case 1:
            iValue = m_iAccY;
            break;
        case 2:
            iValue = m_iAccZ;
            break;
        default:
            iValue = 0;
            return 0;
            break;
    }

    return 1;
}