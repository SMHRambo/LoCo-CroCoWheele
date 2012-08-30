#ifndef CPWMDRIVER_H
#define	CPWMDRIVER_H

#include <stdint.h>

#include "CI2C.h"
#include "CActor.h"

class CPWMDriver : CActor
{
    public:
        CPWMDriver(CI2C * pI2C, uint8_t iAddress);
        virtual ~CPWMDriver();
        
        void setPWM(uint8_t iChannle, uint16_t iDutyCycle);
        void setPeriod(uint16_t iPeriodTime);
        
        uint16_t getPWM(uint8_t iCHannle);
        uint16_t getPeriod();
        
        virtual int8_t setValue(int16_t iValue, uint8_t iChannle);
        
    private:
        CI2C *                  m_pI2C;
        uint8_t                 m_iAddress;
};

#endif	/* PWMDRIVER_H */

