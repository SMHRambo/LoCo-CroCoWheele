#ifndef CBMA180_H
#define CBMA180_H

#include <stdint.h>
#include <boost/thread.hpp>

#include "CVector.h"
#include "CI2C.h"

class CBMA180
{
    public:
        CBMA180(CI2C pI2C);
        virtual ~CBMA180();

        uint16_t getAccXRaw();
        uint16_t getAccYRaw();
        uint16_t getAccZRaw();

        double getAccX();
        double getAccY();
        double getAccZ();

        double getAccAlpha();
        double getAccBeta();
        double getAccGamma();

        CVector getVector();

        uint16_t getAccXRawPerI2C();
        uint16_t getAccYRawPerI2C();
        uint16_t getAccZRawPerI2C();

        double getAccXPerI2C();
        double getAccYPerI2C();
        double getAccZPerI2C();

        double getAccAlphaPerI2C();
        double getAccBetaPerI2C();
        double getAccGammaPerI2C();

        CVector getVectorPerI2C();

        void start();
        void stop();
        void run();

    protected:
    private:
        boost::mutex m_BMA180Mutex;
        CI2C * m_pI2C;
        uint16_t m_iAccX;
        uint16_t m_iAccY;
        uint16_t m_iAccZ;
};

#endif // BMA180_H
