#ifndef CMOTOR_H
#define CMOTOR_H

#include <stdint.h>

#include "CActor.h"

class CMotor : CActor
{
    public:
        CMotor();
        virtual ~CMotor();

        void setSpeed(uint16_t iSpeed);
        uint16_t getSpeed();
        void stop();

    protected:
    private:
};

#endif // CMOTOR_H
