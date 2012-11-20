#include "../include/CITG3200.h"

CITG3200::CITG3200(CI2C * pI2C, uint8_t iAddress)
{
    m_bStop = true;
    m_pI2C = pI2C;
    m_iAddress = iAddress;
    m_iGyroX = 0;
    m_iGyroY = 0;
    m_iGyroZ = 0;
    m_iOffsetX = 0;
    m_iOffsetY = 0;
    m_iOffsetZ = 0;
    m_iScaleX = 1;
    m_iScaleY = 1;
    m_iScaleZ = 1;
}

CITG3200::~CITG3200()
{

}

CITG3200::CLK CITG3200::getClockSource()
{
    std::vector<uint8_t>        viData;
    uint8_t                     iData;
    
    viData.push_back(0x3E);
    
    m_pI2C->lock();

    m_pI2C->writeI2C(m_iAddress,viData);
    m_pI2C->readI2C(m_iAddress, viData, 1);

    m_pI2C->unlock();
    
    iData = viData.at(0);
    
    iData &= 0x7;
    
    return (CITG3200::CLK)iData;
}

void CITG3200::setClockSource(CLK CLKSource)
{
    std::vector<uint8_t>        viData;
    uint8_t                     iData;
    
    viData.push_back(0x3E);
    
    m_pI2C->lock();

    m_pI2C->writeI2C(m_iAddress,viData);
    m_pI2C->readI2C(m_iAddress, viData, 1);
    
    iData = viData.at(0);
    
    iData |= CLKSource;
    
    viData.clear();
    viData.push_back(0x3E);
    viData.push_back(iData);
    
    m_pI2C->writeI2C(m_iAddress,viData);
    
    m_pI2C->unlock();   
}


bool CITG3200::isXgyroStandby()
{
    std::vector<uint8_t>        viData;
    uint8_t                     iData;
    
    viData.push_back(0x3E);
    
    m_pI2C->lock();

    m_pI2C->writeI2C(m_iAddress,viData);
    m_pI2C->readI2C(m_iAddress, viData, 1);

    m_pI2C->unlock();
    
    iData = viData.at(0);
    
    iData >> 5;
    iData &= 0x1;
    
    return iData;    
}

bool CITG3200::isYgyroStandby()
{
    std::vector<uint8_t>        viData;
    uint8_t                     iData;
    
    viData.push_back(0x3E);
    
    m_pI2C->lock();

    m_pI2C->writeI2C(m_iAddress,viData);
    m_pI2C->readI2C(m_iAddress, viData, 1);

    m_pI2C->unlock();
    
    iData = viData.at(0);
    
    iData >> 4;
    iData &= 0x1;
    
    return iData;   
}

bool CITG3200::isZgyroStandby()
{
    std::vector<uint8_t>        viData;
    uint8_t                     iData;
    
    viData.push_back(0x3E);
    
    m_pI2C->lock();

    m_pI2C->writeI2C(m_iAddress,viData);
    m_pI2C->readI2C(m_iAddress, viData, 1);
    
    m_pI2C->unlock();
    
    iData = viData.at(0);
    
    iData >> 3;
    iData &= 0x1;
    
    return iData;    
}

void CITG3200::setXgyroStandby(bool bStatus)
{
    std::vector<uint8_t>        viData;
    uint8_t                     iData;
    uint8_t                     iMask;
    
    viData.push_back(0x3E);
    
    m_pI2C->lock();

    m_pI2C->writeI2C(m_iAddress,viData);
    m_pI2C->readI2C(m_iAddress, viData, 1);
    
    iData = viData.at(0);

    iMask = ~(1 << 5);
    iData = (iData & iMask) | (bStatus << 5);
    
    viData.clear();
    viData.push_back(0x3E);
    viData.push_back(iData);
    
    m_pI2C->writeI2C(m_iAddress,viData);

    m_pI2C->unlock();  
}

void CITG3200::setYgyroStandby(bool bStatus)
{
    std::vector<uint8_t>        viData;
    uint8_t                     iData;
    uint8_t                     iMask;
    
    viData.push_back(0x3E);
    
    m_pI2C->lock();

    m_pI2C->writeI2C(m_iAddress,viData);
    m_pI2C->readI2C(m_iAddress, viData, 1);
    
    iData = viData.at(0);

    iMask = ~(1 << 4);
    iData = (iData & iMask) | (bStatus << 4);
    
    viData.clear();
    viData.push_back(0x3E);
    viData.push_back(iData);
    
    m_pI2C->writeI2C(m_iAddress,viData);

    m_pI2C->unlock();    
}

void CITG3200::setZgyroStandby(bool bStatus)
{
    std::vector<uint8_t>        viData;
    uint8_t                     iData;
    uint8_t                     iMask;
    
    viData.push_back(0x3E);
    
    m_pI2C->lock();

    m_pI2C->writeI2C(m_iAddress,viData);
    m_pI2C->readI2C(m_iAddress, viData, 1);
    
    iData = viData.at(0);

    iMask = ~(1 << 3);
    iData = (iData & iMask) | (bStatus << 3);
    
    viData.clear();
    viData.push_back(0x3E);
    viData.push_back(iData);
    
    m_pI2C->writeI2C(m_iAddress,viData);

    m_pI2C->unlock();    
}

uint8_t CITG3200::getSampleRateDiv()
{
    std::vector<uint8_t>        viData;
    uint8_t                     iData;
    
    viData.push_back(0x15);
    
    m_pI2C->lock();

    m_pI2C->writeI2C(m_iAddress,viData);
    m_pI2C->readI2C(m_iAddress, viData, 1);

    m_pI2C->unlock();
    
    iData = viData.at(0);
    
    return iData;
}

void CITG3200::setSampleRateDiv(uint8_t iSampleRateDiv)
{
    std::vector<uint8_t>        viData;
    
    viData.push_back(0x15);
    viData.push_back(iSampleRateDiv);
    
    m_pI2C->lock();

    m_pI2C->writeI2C(m_iAddress,viData);

    m_pI2C->unlock();    
}

CITG3200::FSR CITG3200::getFSRange()
{
    std::vector<uint8_t>        viData;
    uint8_t                     iData;
    
    viData.push_back(0x16);
    
    m_pI2C->lock();

    m_pI2C->writeI2C(m_iAddress,viData);
    m_pI2C->readI2C(m_iAddress, viData, 1);

    m_pI2C->unlock();
    
    iData = viData.at(0);
    
    iData >> 3;
    
    iData &= 0x3;
    
    return (CITG3200::FSR)iData;  
}

void CITG3200::setFSRange(FSR Range)
{
   
}

CITG3200::FBW CITG3200::getFilterBW()
{
    
}

void CITG3200::setFilterBW(FBW FilterBW)
{
    
}


void CITG3200::reset()
{
    
}

bool CITG3200::isSleepMode()
{
    
}

void CITG3200::setSleepMode(bool bState)
{
    
}

bool CITG3200::isITGReady()
{
    
}

bool CITG3200::isRawDataReady()
{
    
}

int16_t CITG3200::getOffsetX()
{
    float iOffsetX = 0;
    
    m_ITG3200Mutex.lock();
    
    iOffsetX = m_iOffsetX;
    
    m_ITG3200Mutex.unlock();
    
    return iOffsetX;    
}

int16_t CITG3200::getOffsetY()
{
    float iOffsetY = 0;
    
    m_ITG3200Mutex.lock();
    
    iOffsetY = m_iOffsetY;
    
    m_ITG3200Mutex.unlock();
    
    return iOffsetY;    
}

int16_t CITG3200::getOffsetZ()
{
    float iOffsetZ = 0;
    
    m_ITG3200Mutex.lock();
    
    iOffsetZ = m_iOffsetZ;
    
    m_ITG3200Mutex.unlock();
    
    return iOffsetZ;   
}

void CITG3200::setOffsetX(int16_t iOffsetX)
{    
    m_ITG3200Mutex.lock();
    
    m_iOffsetX = iOffsetX;
    
    m_ITG3200Mutex.unlock();  
}

void CITG3200::setOffsetY(int16_t iOffsetY)
{
    m_ITG3200Mutex.lock();
    
    m_iOffsetY = iOffsetY;
    
    m_ITG3200Mutex.unlock();     
}

void CITG3200::setOffsetZ(int16_t iOffsetZ)
{
    m_ITG3200Mutex.lock();
    
    m_iOffsetZ = iOffsetZ;
    
    m_ITG3200Mutex.unlock();    
}

float CITG3200::getScaleX()
{
    float iScaleX = 0;
    
    m_ITG3200Mutex.lock();
    
    iScaleX = m_iScaleX;
    
    m_ITG3200Mutex.unlock();
    
    return iScaleX;    
}

float CITG3200::getScaleY()
{
    float iScaleY = 0;
    
    m_ITG3200Mutex.lock();
    
    iScaleY = m_iScaleY;
    
    m_ITG3200Mutex.unlock();
    
    return iScaleY;    
}

float CITG3200::getScaleZ()
{
    float iScaleZ = 0;
    
    m_ITG3200Mutex.lock();
    
    iScaleZ = m_iScaleZ;
    
    m_ITG3200Mutex.unlock();
    
    return iScaleZ;    
}

void CITG3200::setScaleX(float iScaleX)
{   
    m_ITG3200Mutex.lock();
    
    m_iScaleX = iScaleX;
    
    m_ITG3200Mutex.unlock();   
}

void CITG3200::setScaleY(float iScaleY)
{
    m_ITG3200Mutex.lock();
    
    m_iScaleY = iScaleY;
    
    m_ITG3200Mutex.unlock();    
}

void CITG3200::setScaleZ(float iScaleZ)
{
    m_ITG3200Mutex.lock();
    
    m_iScaleZ = iScaleZ;
    
    m_ITG3200Mutex.unlock();    
}


void CITG3200::zeroCalibration(uint32_t iSamples, uint32_t iDelayMS)
{
    int16_t iOffsetX = 0;
    int16_t iOffsetY = 0;
    int16_t iOffsetZ = 0;

    for (uint32_t i = 0; i < iSamples; i++)
    {

        usleep( iDelayMS * 1000 );
    
        iOffsetX += getGyroXRawPerI2C();
        iOffsetY += getGyroYRawPerI2C();
        iOffsetZ += getGyroZRawPerI2C();
    }
    
    setOffsetX(-iOffsetX / iSamples + 0.5);
    setOffsetY(-iOffsetY / iSamples + 0.5);
    setOffsetZ(-iOffsetZ / iSamples + 0.5);
}


int16_t CITG3200::getGyroXRaw()
{
    int16_t iGyroX = 0;
    
    m_ITG3200Mutex.lock();
    
    iGyroX = m_iGyroX;
    
    m_ITG3200Mutex.unlock();
    
    return iGyroX;
}

int16_t CITG3200::getGyroYRaw()
{
    int16_t iGyroY = 0;
    
    m_ITG3200Mutex.lock();
    
    iGyroY = m_iGyroY;
    
    m_ITG3200Mutex.unlock();
    
    return iGyroY;
}

int16_t CITG3200::getGyroZRaw()
{
    int16_t iGyroZ = 0;
    
    m_ITG3200Mutex.lock();
    
    iGyroZ = m_iGyroZ;
    
    m_ITG3200Mutex.unlock();
    
    return iGyroZ;
}

float CITG3200::getGyroXinDeg()
{
    int16_t                     iX = 0;
    float                       fX = 0;

    m_ITG3200Mutex.lock();
    
    iX = m_iGyroX;
    
    iX += m_iOffsetX;
    
    fX = float(iX) / (14.375 * m_iScaleX);
    
    m_ITG3200Mutex.unlock();
    
    return fX;    
}

float CITG3200::getGyroYinDeg()
{
    int16_t                     iY = 0;
    float                       fY = 0;

    m_ITG3200Mutex.lock();
    
    iY = m_iGyroY;
    
    iY += m_iOffsetY;
    
    fY = float(iY) / (14.375 * m_iScaleY);   
    
    m_ITG3200Mutex.unlock();
    
    return fY;   
}

float CITG3200::getGyroZinDeg()
{
    int16_t                     iZ = 0;
    float                       fZ = 0;

    m_ITG3200Mutex.lock();
    
    iZ = m_iGyroZ;
    
    iZ += m_iOffsetZ;
    
    fZ = float(iZ) / (14.375 * m_iScaleZ);   
    
    m_ITG3200Mutex.unlock();
    
    return fZ;
}

float CITG3200::getGyroXinRad()
{
    int16_t                     iX = 0;
    float                       fX = 0;
    
    m_ITG3200Mutex.lock();
    
    iX = m_iGyroX;
    
    iX += m_iOffsetX;
    
    fX = float(iX) / ((14.375 * m_iScaleX) / 0.0174532925);
    
    m_ITG3200Mutex.unlock();
   
    return fX;    
}

float CITG3200::getGyroYinRad()
{
    int16_t                     iY = 0;
    float                       fY = 0;
    
    m_ITG3200Mutex.lock();
    
    iY = m_iGyroY;
    
    iY += m_iOffsetY;
    
    fY = float(iY) / ((14.375 * m_iScaleY) / 0.0174532925);
    
    m_ITG3200Mutex.unlock();
   
    return fY;     
}

float CITG3200::getGyroZinRad()
{
    int16_t                     iZ = 0;
    float                       fZ = 0;
    
    m_ITG3200Mutex.lock();
    
    iZ = m_iGyroZ;
    
    iZ += m_iOffsetZ;
    
    fZ = float(iZ) / ((14.375 * m_iScaleZ) / 0.0174532925);
    
    m_ITG3200Mutex.unlock();
   
    return fZ;     
}


int16_t CITG3200::getGyroXRawPerI2C()
{
    std::vector<uint8_t>        viData;
    int16_t                     iX = 0;
    
    viData.push_back(0x1D);
    
    m_pI2C->lock();

    m_pI2C->writeI2C(m_iAddress,viData);
    if(m_pI2C->readI2C(m_iAddress, viData, 2))
    {
        iX = viData[0] << 8 | viData[1];
    }

    m_pI2C->unlock();
    
    return iX;
}

int16_t CITG3200::getGyroYRawPerI2C()
{
    std::vector<uint8_t>        viData;
    int16_t                     iY = 0;
    
    viData.push_back(0x1F);
    
    m_pI2C->lock();

    m_pI2C->writeI2C(m_iAddress,viData);
    if(m_pI2C->readI2C(m_iAddress, viData, 2))
    {
        iY = viData[0] << 8 | viData[1];
    }

    m_pI2C->unlock();
    
    return iY;
}

int16_t CITG3200::getGyroZRawPerI2C()
{
    std::vector<uint8_t>        viData;
    int16_t                     iZ = 0;
    
    viData.push_back(0x21);
    
    m_pI2C->lock();

    m_pI2C->writeI2C(m_iAddress,viData);
    if(m_pI2C->readI2C(m_iAddress, viData, 2))
    {
        iZ = viData[0] << 8 | viData[1];
    }

    m_pI2C->unlock();
    
    return iZ;
}

float CITG3200::getGyroXinDegPerI2C()
{
    std::vector<uint8_t>        viData;
    int16_t                     iX = 0;
    float                       fX = 0;
    
    viData.push_back(0x1D);
    
    m_pI2C->lock();

    m_pI2C->writeI2C(m_iAddress,viData);
    if(m_pI2C->readI2C(m_iAddress, viData, 2))
    {
        iX = viData[0] << 8 | viData[1];
    }

    m_pI2C->unlock();
    
    m_ITG3200Mutex.lock();
    
    iX += m_iOffsetX;
    
    fX = float(iX) / (14.375 * m_iScaleX);   
    
    m_ITG3200Mutex.unlock();
    
    return fX;
}

float CITG3200::getGyroYinDegPerI2C()
{
    std::vector<uint8_t>        viData;
    int16_t                     iY = 0;
    float                       fY = 0;
    
    viData.push_back(0x1F);
    
    m_pI2C->lock();

    m_pI2C->writeI2C(m_iAddress,viData);
    if(m_pI2C->readI2C(m_iAddress, viData, 2))
    {
        iY = viData[0] << 8 | viData[1];
    }

    m_pI2C->unlock();
    
    m_ITG3200Mutex.lock();
    
    fY += m_iOffsetY;
    
    fY = float(iY) / (14.375 * m_iScaleY);   
    
    m_ITG3200Mutex.unlock();
    
    return fY;
}

float CITG3200::getGyroZinDegPerI2C()
{
    std::vector<uint8_t>        viData;
    int16_t                     iZ = 0;
    float                       fZ = 0;
    
    viData.push_back(0x21);
    
    m_pI2C->lock();

    m_pI2C->writeI2C(m_iAddress,viData);
    if(m_pI2C->readI2C(m_iAddress, viData, 2))
    {
        iZ = viData[0] << 8 | viData[1];
    }

    m_pI2C->unlock();
    
    m_ITG3200Mutex.lock();
    
    iZ += m_iOffsetZ;
    
    fZ = float(iZ) / (14.375 * m_iScaleZ);
    
    m_ITG3200Mutex.unlock();

    return fZ;    
}

float CITG3200::getGyroXinRadPerI2C()
{
    std::vector<uint8_t>        viData;
    int16_t                     iX = 0;
    float                       fX = 0;
    
    viData.push_back(0x1D);
    
    m_pI2C->lock();

    m_pI2C->writeI2C(m_iAddress,viData);
    if(m_pI2C->readI2C(m_iAddress, viData, 2))
    {
        iX = viData[0] << 8 | viData[1];
    }

    m_pI2C->unlock();
    
    m_ITG3200Mutex.lock();
    
    iX += m_iOffsetX;
    
    fX = float(iX) / ((14.375 * m_iScaleX) / 0.0174532925);
    
    m_ITG3200Mutex.unlock();
   
    return fX;
}

float CITG3200::getGyroYinRadPerI2C()
{
    std::vector<uint8_t>        viData;
    int16_t                     iY = 0;
    float                       fY = 0;
    
    viData.push_back(0x1F);
    
    m_pI2C->lock();

    m_pI2C->writeI2C(m_iAddress,viData);
    if(m_pI2C->readI2C(m_iAddress, viData, 2))
    {
        iY = viData[0] << 8 | viData[1];
    }

    m_pI2C->unlock();
    
    m_ITG3200Mutex.lock();
    
    iY += m_iOffsetY;
    
    fY = float(iY) / ((14.375 * m_iScaleY) / 0.0174532925);
    
    m_ITG3200Mutex.unlock();

    return fY;    
}

float CITG3200::getGyroZinRadPerI2C()
{
    std::vector<uint8_t>        viData;
    int16_t                     iZ = 0;
    float                       fZ = 0;
    
    viData.push_back(0x21);
    
    m_pI2C->lock();

    m_pI2C->writeI2C(m_iAddress,viData);
    if(m_pI2C->readI2C(m_iAddress, viData, 2))
    {
        iZ = viData[0] << 8 | viData[1];
    }

    m_pI2C->unlock();
    
    m_ITG3200Mutex.lock();
    
    iZ += m_iOffsetZ;
    
    fZ = float(iZ) / ((14.375 * m_iScaleZ) / 0.0174532925);
    
    m_ITG3200Mutex.unlock();

    return fZ;    
}

void CITG3200::start()
{
    m_bStop = false;
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
        do
        {
            
        }
        while(!m_bStop);
    }
    catch(boost::thread_interrupted&)
    {
        
    }
}

bool CITG3200::getValue(float &iValue, uint8_t iChannle)
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