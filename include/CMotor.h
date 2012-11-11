#ifndef CMOTOR_H
#define CMOTOR_H

#include <stdint.h>

#include "CPWMDriver.h"
#include "CActor.h"

class CMotor : public CActor
{
    public:
        CMotor(CPWMDriver * pPWMDriver, uint8_t iChannle);
        virtual ~CMotor();

        void setSpeed(int16_t iSpeed);
        int16_t getSpeed();
        
        void stop();
        
        virtual bool setValue(float iValue, uint8_t iChannle);

    private:
        CPWMDriver *                  m_pPWMDriver;
};

#endif // CMOTOR_H
