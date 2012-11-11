#ifndef CITG3200_H
#define CITG3200_H

#include <stdint.h>
#include <boost/thread.hpp>

#include "CVector.h"
#include "CI2C.h"
#include "CSensor.h"

class CITG3200  : CSensor
{
    public:
        CITG3200(CI2C * pI2C, uint8_t iAddress);
        virtual ~CITG3200();

        uint16_t getGyroXRaw();
        uint16_t getGyroYRaw();
        uint16_t getGyroZRaw();

        float getGyroX();
        float getGyroY();
        float getGyroZ();

        float getGyroAlpha();
        float getGyroBeta();
        float getGyroGamma();

        CVector getGyroVector();

        uint16_t getGyroXRawPerI2C();
        uint16_t getGyroYRawPerI2C();
        uint16_t getGyroZRawPerI2C();

        float getGyroXPerI2C();
        float getGyroYPerI2C();
        float getGyroZPerI2C();

        float getGyroAlphaPerI2C();
        float getGyroBetaPerI2C();
        float getGyroGammaPerI2C();

        CVector getGyroVectorPerI2C();

        void start();
        void stop();
        void kill();
        void run();

        virtual bool getValue(float &iValue, uint8_t iChannle);
        
    private:
        boost::recursive_mutex  m_ITG3200Mutex;
        boost::thread           m_ITG3200Thread;
        bool                    m_bStop;
        CI2C *                  m_pI2C;
        uint8_t                 m_iAddress;
        uint16_t                m_iGyroX;
        uint16_t                m_iGyroY;
        uint16_t                m_iGyroZ;
};

#endif // ITG3200_H
