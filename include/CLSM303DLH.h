#ifndef CLSM303DLH_H
#define CLSM303DLH_H

#include <stdint.h>
#include <boost/thread.hpp>

#include "CVector.h"
#include "CI2C.h"

class CLSM303DLH
{
    public:
        CLSM303DLH(CI2C pI2C);
        virtual ~CLSM303DLH();

        uint16_t getAccXRaw();
        uint16_t getAccYRaw();
        uint16_t getAccZRaw();

        double getAccX();
        double getAccY();
        double getAccZ();

        double getAccAlpha();
        double getAccBeta();
        double getAccGamma();

        CVector getAccVector();

        uint16_t getAccXRawPerI2C();
        uint16_t getAccYRawPerI2C();
        uint16_t getAccZRawPerI2C();

        double getAccXPerI2C();
        double getAccYPerI2C();
        double getAccZPerI2C();

        double getAccAlphaPerI2C();
        double getAccBetaPerI2C();
        double getAccGammaPerI2C();

        CVector getAccVectorPerI2C();

        uint16_t getMagXRaw();
        uint16_t getMagYRaw();
        uint16_t getMagZRaw();

        double getMagX();
        double getMagY();
        double getMagZ();

        double getMagAlpha();
        double getMagBeta();
        double getMagGamma();

        CVector getMagVector();

        uint16_t getMagXRawPerI2C();
        uint16_t getMagYRawPerI2C();
        uint16_t getMagZRawPerI2C();

        double getMagXPerI2C();
        double getMagYPerI2C();
        double getMagZPerI2C();

        double getMagAlphaPerI2C();
        double getMagBetaPerI2C();
        double getMagGammaPerI2C();

        CVector getMagVectorPerI2C();

        void start();
        void stop();
        void run();

    protected:
    private:
        boost::mutex m_LSM303DLHMutex;
        CI2C * m_pI2C;
        uint16_t m_iAccX;
        uint16_t m_iAccY;
        uint16_t m_iAccZ;
        uint16_t m_iMagX;
        uint16_t m_iMagY;
        uint16_t m_iMagZ;
};

#endif // LSM303DLH_H
