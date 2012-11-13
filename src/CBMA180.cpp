#include "../include/CBMA180.h"

//Construktor
//Parameter:
//CI2C * pI2C an i2c bus object to communicate with the sensor
//uint8_t iAddress the address of the sensor on the i2c bus
CBMA180::CBMA180(CI2C * pI2C, uint8_t iAddress)
{
    m_pI2C = pI2C;
    m_iAddress = iAddress;
    m_bStop = false;
    m_iBits = 14;
    m_iRange = 2;
}

CBMA180::~CBMA180()
{

}

//return the raw acceleration value of the x axis from the BMA180 sensor saved in the object
uint16_t CBMA180::getAccXRaw()
{
    uint16_t iAccX = 0;

    m_BMA180Mutex.lock();

    iAccX = m_iAccX;

    m_BMA180Mutex.unlock();

    return iAccX;
}

//return the raw acceleration value of the y axis from the BMA180 sensor saved in the object
uint16_t CBMA180::getAccYRaw()
{
    uint16_t iAccY = 0;

    m_BMA180Mutex.lock();

    iAccY = m_iAccY;

    m_BMA180Mutex.unlock();

    return iAccY;
}

//return the raw acceleration value of the z axis from the BMA180 sensor saved in the object
uint16_t CBMA180::getAccZRaw()
{
    uint16_t iAccZ = 0;

    m_BMA180Mutex.lock();

    iAccZ = m_iAccZ;

    m_BMA180Mutex.unlock();

    return iAccZ;
}

//return the raw but signed acceleration value of the x axis from the BMA180 sensor saved in the object
int16_t CBMA180::getAccXSignedRaw()
{
    uint16_t iAccX = 0;

    m_BMA180Mutex.lock();

    iAccX = m_iAccX << (16 - m_iBits);

    m_BMA180Mutex.unlock();

    return iAccX;
}

//return the raw but signed acceleration value of the y axis from the BMA180 sensor saved in the object
int16_t CBMA180::getAccYSignedRaw()
{
    uint16_t iAccY = 0;

    m_BMA180Mutex.lock();

    iAccY = m_iAccY << (16 - m_iBits);

    m_BMA180Mutex.unlock();

    return iAccY;
}

//return the raw but signed acceleration value of the z axis from the BMA180 sensor saved in the object
int16_t CBMA180::getAccZSignedRaw()
{
    uint16_t iAccZ = 0;

    m_BMA180Mutex.lock();

    iAccZ = m_iAccZ << (16 - m_iBits);

    m_BMA180Mutex.unlock();

    return iAccZ;
}


float CBMA180::getAccX()
{
    float fAccX = 0;

    m_BMA180Mutex.lock();

    fAccX = ((float)(m_iAccX << (16 - m_iBits)) / 32768) * m_iRange;
    
    m_BMA180Mutex.unlock();
    
    return fAccX;
}

float CBMA180::getAccY()
{
    float fAccY = 0;

    m_BMA180Mutex.lock();

    fAccY = ((float)(m_iAccY << (16 - m_iBits)) / 32768) * m_iRange;

    m_BMA180Mutex.unlock();

    return fAccY;
}

float CBMA180::getAccZ()
{
    float fAccZ = 0;

    m_BMA180Mutex.lock();

    fAccZ = ((float)(m_iAccZ << (16 - m_iBits)) / 32768) * m_iRange;

    m_BMA180Mutex.unlock();

    return fAccZ;
}

float CBMA180::getAccAlpha()
{
    float fAlpha = 0;

    m_BMA180Mutex.lock();

    fAlpha = getAccX() / sqrt(pow(getAccX(), 2) + pow(getAccY(), 2) + pow(getAccZ(), 2));

    m_BMA180Mutex.unlock();

    return fAlpha;
}

float CBMA180::getAccBeta()
{
    float fBeta = 0;

    m_BMA180Mutex.lock();

    fBeta = getAccY() / sqrt(pow(getAccX(), 2) + pow(getAccY(), 2) + pow(getAccZ(), 2));

    m_BMA180Mutex.unlock();

    return fBeta;
}

float CBMA180::getAccGamma()
{
    float fGamma = 0;

    m_BMA180Mutex.lock();

    fGamma = getAccZ() / sqrt(pow(getAccX(), 2) + pow(getAccY(), 2) + pow(getAccZ(), 2));

    m_BMA180Mutex.unlock();

    return fGamma;
}

CVector CBMA180::getVector()
{

}

uint16_t CBMA180::getAccXRawPerI2C()
{
    std::vector<uint8_t> viData;
    uint16_t iX = 0;

    viData.push_back(0x06);

    m_pI2C->lock();
    m_pI2C->writeI2C(m_iAddress, viData);
    if (m_pI2C->readI2C(m_iAddress, viData, 2))
    {
        iX = *((uint16_t *)&viData.at(0)) >> (16 - m_iBits);
    }
    
    m_pI2C->unlock();

    return iX;
}

uint16_t CBMA180::getAccYRawPerI2C()
{
    std::vector<uint8_t> viData;
    uint16_t iY = 0;

    viData.push_back(0x04);

    m_pI2C->lock();
    m_pI2C->writeI2C(m_iAddress, viData);
    if (m_pI2C->readI2C(m_iAddress, viData, 2))
    {
        iY = *((uint16_t *)&viData.at(0)) >> (16 - m_iBits);
    }
    m_pI2C->unlock();

    return iY;
}

uint16_t CBMA180::getAccZRawPerI2C()
{
    std::vector<uint8_t> viData;
    uint16_t iZ = 0;

    viData.push_back(0x02);

    m_pI2C->lock();
    m_pI2C->writeI2C(m_iAddress, viData);
    if (m_pI2C->readI2C(m_iAddress, viData, 2))
    {
        iZ = *((uint16_t *)&viData.at(0)) >> (16 - m_iBits);
    }
    m_pI2C->unlock();

    return iZ;
}

int16_t CBMA180::getAccXSignedRawPerI2C()
{
    std::vector<uint8_t> viData;
    uint16_t iX = 0;

    viData.push_back(0x06);

    m_pI2C->lock();
    m_pI2C->writeI2C(m_iAddress, viData);
    if (m_pI2C->readI2C(m_iAddress, viData, 2))
    {
        iX = (*((uint16_t *)&viData.at(0)) >> (16 - m_iBits)) << (16 - m_iBits);
    }
    
    m_pI2C->unlock();

    return iX;
}

int16_t CBMA180::getAccYSignedRawPerI2C()
{
    std::vector<uint8_t> viData;
    uint16_t iY = 0;

    viData.push_back(0x04);

    m_pI2C->lock();
    m_pI2C->writeI2C(m_iAddress, viData);
    if (m_pI2C->readI2C(m_iAddress, viData, 2))
    {
        iY = (*((uint16_t *)&viData.at(0)) >> (16 - m_iBits)) << (16 - m_iBits);
    }
    m_pI2C->unlock();

    return iY;
}

int16_t CBMA180::getAccZSignedRawPerI2C()
{
    std::vector<uint8_t> viData;
    uint16_t iZ = 0;

    viData.push_back(0x02);

    m_pI2C->lock();
    m_pI2C->writeI2C(m_iAddress, viData);
    if (m_pI2C->readI2C(m_iAddress, viData, 2))
    {
        iZ = (*((uint16_t *)&viData.at(0)) >> (16 - m_iBits)) << (16 - m_iBits);
    }
    m_pI2C->unlock();

    return iZ;
}

float CBMA180::getAccXPerI2C()
{
    std::vector<uint8_t>        viData;
    int16_t                    iX = 0;
    float                       fX = 0;
    
    viData.push_back(0x06);
    
    m_pI2C->lock();
    m_pI2C->writeI2C(m_iAddress,viData);
    if(m_pI2C->readI2C(m_iAddress,viData,2))
    {
        iX = (viData[1] | viData[1] << 8) >> (16 - m_iBits);
    }
    m_pI2C->unlock();
    
    fX = (float)iX / (pow(2,m_iBits) / (2 * m_iRange));
    
    return fX;
}

float CBMA180::getAccYPerI2C()
{
    std::vector<uint8_t>        viData;
    uint16_t                    iY = 0;
    float                       fY = 0;
    
    viData.push_back(0x04);
    
    m_pI2C->lock();
    m_pI2C->writeI2C(m_iAddress,viData);
    if(m_pI2C->readI2C(m_iAddress,viData,2))
    {
        iY = (*((uint16_t *)viData.data()) >> (16 - m_iBits)) << (16 - m_iBits);
    }
    m_pI2C->unlock();
    
    fY = (float)iY / 32768;
    
    fY *= m_iRange;
    
    return fY;
}

float CBMA180::getAccZPerI2C()
{
    std::vector<uint8_t>        viData;
    uint16_t                    iZ = 0;
    float                       fZ = 0;
    
    viData.push_back(0x02);
    
    m_pI2C->lock();
    m_pI2C->writeI2C(m_iAddress,viData);
    if(m_pI2C->readI2C(m_iAddress,viData,2))
    {
        iZ = (*((uint16_t *)viData.data()) >> (16 - m_iBits)) << (16 - m_iBits);
    }
    m_pI2C->unlock();
    
    fZ = (float)iZ / 32768;
    
    fZ *= m_iRange;
    
    return fZ;
}

float CBMA180::getAccAlphaPerI2C()
{
    std::vector<uint8_t>        viData;
    float                       fX = 0;
    float                       fY = 0;
    float                       fZ = 0;
    
    
    viData.push_back(0x02);
    
    m_pI2C->lock();
    m_pI2C->writeI2C(m_iAddress,viData);
    if(m_pI2C->readI2C(m_iAddress,viData,6))
    {
        fX = ((float)((*((int16_t *)&viData.at(4)) >> (16 - m_iBits)) << (16 - m_iBits)) / 32768) * m_iRange;
        fY = ((float)((*((int16_t *)&viData.at(2)) >> (16 - m_iBits)) << (16 - m_iBits)) / 32768) * m_iRange;
        fZ = ((float)((*((int16_t *)&viData.at(0)) >> (16 - m_iBits)) << (16 - m_iBits)) / 32768) * m_iRange;       
    }
    m_pI2C->unlock();
    
    return fX / sqrt(pow(fX, 2) + pow(fY, 2) + pow(fZ, 2));
}

float CBMA180::getAccBetaPerI2C()
{
    std::vector<uint8_t>        viData;
    float                       fX = 0;
    float                       fY = 0;
    float                       fZ = 0;
    
    
    viData.push_back(0x02);
    
    m_pI2C->lock();
    m_pI2C->writeI2C(m_iAddress,viData);
    if(m_pI2C->readI2C(m_iAddress,viData,6))
    {
        fX = ((float)((*((int16_t *)&viData.at(4)) >> (16 - m_iBits)) << (16 - m_iBits)) / 32768) * m_iRange;
        fY = ((float)((*((int16_t *)&viData.at(2)) >> (16 - m_iBits)) << (16 - m_iBits)) / 32768) * m_iRange;
        fZ = ((float)((*((int16_t *)&viData.at(0)) >> (16 - m_iBits)) << (16 - m_iBits)) / 32768) * m_iRange;       
    }
    m_pI2C->unlock();
    
    return fY / sqrt(pow(fX, 2) + pow(fY, 2) + pow(fZ, 2));
}

float CBMA180::getAccGammaPerI2C()
{
    std::vector<uint8_t>        viData;
    float                       fX = 0;
    float                       fY = 0;
    float                       fZ = 0;
    
    
    viData.push_back(0x02);
    
    m_pI2C->lock();
    m_pI2C->writeI2C(m_iAddress,viData);
    if(m_pI2C->readI2C(m_iAddress,viData,6))
    {
        fX = ((float)((*((int16_t *)&viData.at(4)) >> (16 - m_iBits)) << (16 - m_iBits)) / 32768) * m_iRange;
        fY = ((float)((*((int16_t *)&viData.at(2)) >> (16 - m_iBits)) << (16 - m_iBits)) / 32768) * m_iRange;
        fZ = ((float)((*((int16_t *)&viData.at(0)) >> (16 - m_iBits)) << (16 - m_iBits)) / 32768) * m_iRange;       
    }
    m_pI2C->unlock();
    
    return fZ / sqrt(pow(fX, 2) + pow(fY, 2) + pow(fZ, 2));
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

void CBMA180::start()
{
    m_BMA180Thread = boost::thread(&CBMA180::run, this);
}

void CBMA180::stop()
{
    m_bStop = true;
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
        std::vector<uint8_t> viDataIN;
        std::vector<uint8_t> viDataOUT;
        viDataOUT.push_back(0x02);
        
        while (!m_bStop)
        {
            m_pI2C->lock();
            m_pI2C->writeI2C(m_iAddress, viDataOUT);
            if (m_pI2C->readI2C(m_iAddress, viDataIN, 6))
            {
                m_iAccX = *((int16_t *)&viDataIN.at(4)) >> (16 - m_iBits);
                m_iAccY = *((int16_t *)&viDataIN.at(2)) >> (16 - m_iBits);
                m_iAccZ = *((int16_t *)&viDataIN.at(0)) >> (16 - m_iBits);
            }
            m_pI2C->unlock();
        }
    }
    catch (boost::thread_interrupted&)
    {

    }
}

bool CBMA180::getValue(float &iValue, uint8_t iChannle)
{
    switch(iChannle)
    {
        case 0:
            iValue = getAccX();
            break;
        case 1:
            iValue = getAccY();
            break;
        case 2:
            iValue = getAccZ();
            break;
        case 3:
            iValue = getAccXPerI2C();
            break;
        case 4:
            iValue = getAccYPerI2C();
            break;
        case 5:
            iValue = getAccZPerI2C();
            break;
        case 6:
            iValue = getAccAlpha();
            break;
        case 7:
            iValue = getAccBeta();
            break;
        case 8:
            iValue = getAccGamma();
            break;
        case 9:
            iValue = getAccAlphaPerI2C();
            break;
        case 10:
            iValue = getAccBetaPerI2C();
            break;
        case 11:
            iValue = getAccGammaPerI2C();
            break;
        default:
            iValue = 0;
            return 0;
            break;
    }

    return 1;
}