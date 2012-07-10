#ifndef CI2C_H
#define CI2C_H

#include <stdint.h>
#include <string>
#include <vector>
#include <boost/thread.hpp>

class CI2C
{
    public:
        CI2C(std::string sDevice);
        virtual ~CI2C();

        bool read(uint8_t iAddress, std::vector<uint8_t> & viData, uint8_t iLength);
        bool write(uint8_t iAddress, std::vector<uint8_t> viData);

    protected:
    private:
        boost::mutex m_I2CMutex;
        int32_t m_i2cSocket;
};

#endif // CI2C_H
