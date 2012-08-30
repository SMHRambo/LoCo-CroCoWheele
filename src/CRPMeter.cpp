#include "../include/CRPMeter.h"

CRPMeter::CRPMeter(CI2C * pI2C, uint8_t iAddress)
{
    m_pI2C = pI2C;
    m_iAddress = iAddress;
    m_bStop = false;
}

CRPMeter::~CRPMeter() {
}


void CRPMeter::start()
{
    m_RPMeterThread = boost::thread(&CRPMeter::run, this);
}

void CRPMeter::stop()
{
    m_bStop = true;
    m_RPMeterThread.join();
}

void CRPMeter::kill()
{
    m_RPMeterThread.interrupt();
    m_RPMeterThread.join();
}

void CRPMeter::run()
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
                                
            }
            m_pI2C->unlock();
        }
    }
    catch (boost::thread_interrupted&)
    {

    }
}
