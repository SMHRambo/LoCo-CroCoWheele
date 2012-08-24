#include "../include/RPMeter.h"

RPMeter::RPMeter(CI2C * pI2C, uint8_t iAddress)
{
    m_pI2C = pI2C;
    m_iAddress = iAddress;
    m_bStop = false;
}

RPMeter::~RPMeter() {
}


void RPMeter::start()
{
    m_RPMeterThread = boost::thread(&RPMeter::run, this);
}

void RPMeter::stop()
{
    m_bStop = true;
    m_RPMeterThread.join();
}

void RPMeter::kill()
{
    m_RPMeterThread.interrupt();
    m_RPMeterThread.join();
}

void RPMeter::run()
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
