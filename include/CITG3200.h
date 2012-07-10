#ifndef CITG3200_H
#define CITG3200_H

#include <stdint.h>
#include <boost/thread.hpp>

#include "CVector.h"
#include "CI2C.h"

class CITG3200
{
    public:
        CITG3200();
        virtual ~CITG3200();

        uint16_t getGyroXRaw();
        uint16_t getGyroYRaw();
        uint16_t getGyroZRaw();

        double getGyroX();
        double getGyroY();
        double getGyroZ();

        double getGyroAlpha();
        double getGyroBeta();
        double getGyroGamma();

        CVector getGyroVector();

        uint16_t getGyroXRawPerI2C();
        uint16_t getGyroYRawPerI2C();
        uint16_t getGyroZRawPerI2C();

        double getGyroXPerI2C();
        double getGyroYPerI2C();
        double getGyroZPerI2C();

        double getGyroAlphaPerI2C();
        double getGyroBetaPerI2C();
        double getGyroGammaPerI2C();

        CVector getGyroVectorPerI2C();

        void start();
        void stop();
        void run();

    protected:
    private:
        boost::mutex m_ITG3200Mutex;
        CI2C * m_pI2C;
        uint16_t m_iGyroX;
        uint16_t m_iGyroY;
        uint16_t m_iGyroZ;
};

#endif // ITG3200_H
