#include "../include/CI2C.h"

CI2C::CI2C(std::string sDevice)
{
    try
    {
        lock();
        
        m_i2cSocket = open(sDevice.data(), O_RDWR);

        if (m_i2cSocket < 0)
        {
            std::cout << "Could not open " << sDevice << strerror(errno) << std::endl;
            throw 0;
        }
        
        unlock();
    }
    catch(...)
    {
        unlock();
        std::cout << "CI2C constructor failed." << std::endl;  
        throw 0;
    }
}

CI2C::~CI2C()
{
    try
    {
        lock();
        
        close(m_i2cSocket);
    
        unlock();
    }
    catch(...)
    {
        unlock();
        std::cout << "CI2C destructor failed." << std::endl;  
        throw 0;    
    }
}

bool CI2C::readI2C(uint8_t iAddress, std::vector<uint8_t> & viData, uint8_t iLength)
{
    try
    {
        lock();
        
        viData.clear();
        viData.resize(iLength, 0);

        int iError = 0;

        iError = ioctl(m_i2cSocket,I2C_SLAVE,iAddress);

        if (iError < 0)
        {
            std::cout << "Failed to acquire bus access and/or talk to slave."  << std::endl;
            unlock();
            return 0;
        }
        
        iError = read(m_i2cSocket,viData.data(),iLength);

        if(iError != iLength)
        {
            viData.resize(iError);
            std::cout << ""  << std::endl;
            unlock();
            return 0;
        }

        unlock();
        return 1;       
    }
    catch(...)
    {
        unlock();
        std::cout << "CI2C readI2C failed." << std::endl;  
        throw 0; 
    }

}

bool CI2C::writeI2C(uint8_t iAddress, std::vector<uint8_t> viData)
{
    try
    {
        lock();
        
        int iError = 0;

        iError = ioctl(m_i2cSocket,I2C_SLAVE,iAddress);

        if (iError < 0)
        {
            std::cout << "Failed to acquire bus access and/or talk to slave."  << std::endl;
            unlock();
            return 0;    
        }

        iError = write(m_i2cSocket,viData.data(),viData.size());

        if (iError != viData.size())
        {
            std::cout << ""  << std::endl;
            unlock();
            return 0;
        }
        
        unlock();
        return 1;        
    }
    catch(...)
    {
        unlock();
        std::cout << "CI2C writeI2C failed." << std::endl;  
        throw 0;
    }
}

void CI2C::lock()
{
    m_I2CMutex.lock();
}

void CI2C::unlock()
{
    m_I2CMutex.unlock();
}