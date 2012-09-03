#ifndef CMOTOR_H
#define CMOTOR_H

#include <stdint.h>

#include "CPWMDriver.h"
#include "CActor.h"

class CMotor : CActor
{
    public:
        CMotor(CPWMDriver * pPWMDriver, uint8_t iChannle);
        virtual ~CMotor();

        void setSpeed(int16_t iSpeed);
        int16_t getSpeed();
        
        void stop();
        
        virtual int8_t setValue(int16_t iValue, uint8_t iChannle);

    private:
        CPWMDriver *                  m_pPWMDriver;
};

#endif // CMOTOR_H
