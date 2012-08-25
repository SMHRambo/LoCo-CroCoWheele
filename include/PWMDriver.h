#ifndef PWMDRIVER_H
#define	PWMDRIVER_H

#include <stdint.h>

#include "CI2C.h"

class PWMDriver
{
    public:
        PWMDriver(CI2C * pI2C, uint8_t iAddress);
        virtual ~PWMDriver();
        
        void setPWM(uint8_t iChannle, uint16_t iDutyCycle);
        void setPeriod(uint16_t iPeriodTime);
        
        uint16_t getPWM(uint8_t iCHannle);
        uint16_t getPeriod();
        
    private:
        CI2C *                  m_pI2C;
        uint8_t                 m_iAddress;
};

#endif	/* PWMDRIVER_H */

