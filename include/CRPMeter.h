#ifndef CRPMETER_H
#define	CRPMETER_H

#include <stdint.h>
#include <boost/thread.hpp>

#include "CI2C.h"
#include "CSensor.h"

class CRPMeter  : CSensor
{
    public:
        CRPMeter(CI2C * pI2C, uint8_t iAddress);
        virtual ~CRPMeter();
        
        void start();
        void stop();
        void kill();
        void run();
        
        virtual int8_t getValue(int16_t &iValue, uint8_t iChannle);
        
    private:
        boost::recursive_mutex  m_RPMeterMutex;
        boost::thread           m_RPMeterThread;
        bool                    m_bStop;
        CI2C *                  m_pI2C;
        uint8_t                 m_iAddress;
        int16_t                 m_iSpeed;

};

#endif	/* RPMETER_H */

