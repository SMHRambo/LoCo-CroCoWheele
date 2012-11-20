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

CITG3200::CLK CITG3200::getClockSource()
{
    
}

void CITG3200::setClockSource(CLK CLKsource)
{
    
}


bool CITG3200::isXgyroStandby()
{
    
}

bool CITG3200::isYgyroStandby()
{
    
}

bool CITG3200::isZgyroStandby()
{
    
}

void CITG3200::setXgyroStandby(bool bStatus)
{
    
}

void CITG3200::setYgyroStandby(bool bStatus)
{
    
}

void CITG3200::setZgyroStandby(bool bStatus)
{
    
}

uint8_t CITG3200::getSampleRateDiv()
{
    
}

void CITG3200::setSampleRateDiv(uint8_t iSampleRateDiv)
{
    
}

CITG3200::FSR CITG3200::getFSRange()
{
    
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
    
}

int16_t CITG3200::getOffsetY()
{
    
}

int16_t CITG3200::getOffsetZ()
{
    
}


void CITG3200::setOffsetX(int16_t iOffsetX)
{
    
}

void CITG3200::setOffsetY(int16_t iOffsetY)
{
    
}

void CITG3200::setOffsetZ(int16_t iOffsetZ)
{
    
}


float CITG3200::getScaleX()
{
    
}

float CITG3200::getScaleY()
{
    
}

float CITG3200::getScaleZ()
{
    
}

void CITG3200::setScaleX(float iScaleX)
{
    
}

void CITG3200::setScaleY(float iScaleY)
{
    
}

void CITG3200::setScaleZ(float iScaleZ)
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

float getGyroXinDeg()
{
    
}

float getGyroYinDeg()
{
    
}

float getGyroZinDeg()
{
    
}


float getGyroXinRad()
{
    
}

float getGyroYinRad()
{
    
}

float getGyroZinRad()
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

float CITG3200::getGyroXinDegPerI2C()
{
    
}

float CITG3200::getGyroYinDegPerI2C()
{
    
}

float CITG3200::getGyroZinDegPerI2C()
{
    
}


float CITG3200::getGyroXinRadPerI2C()
{
    
}

float CITG3200::getGyroYinRadPerI2C()
{
    
}

float CITG3200::getGyroZinRadPerI2C()
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