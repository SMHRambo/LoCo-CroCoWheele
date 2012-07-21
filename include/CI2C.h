#ifndef CI2C_H
#define CI2C_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string>
#include <vector>
#include <boost/thread.hpp>
//#include <glib-2.0/glib.h>
//#include <glib-2.0/glib/gprintf.h>
//#include <glib.h>
//#include <glib/gprintf.h>
#include <errno.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>




class CI2C
{
    public:
        CI2C(std::string sDevice);
        virtual ~CI2C();

        bool readI2C(uint8_t iAddress, std::vector<uint8_t> & viData, uint8_t iLength);
        bool readI2C(uint8_t iAddress, uint8_t * pData, uint8_t iLength);
        bool writeI2C(uint8_t iAddress, std::vector<uint8_t> viData);
        
        void lock();
        void unlock();

    protected:
    private:
        boost::recursive_mutex  m_I2CMutex;
        int32_t                 m_i2cSocket;
};

#endif // CI2C_H
