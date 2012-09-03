#ifndef CBMA180_H
#define CBMA180_H

#include <stdint.h>
#include <boost/thread.hpp>

#include "CVector.h"
#include "CI2C.h"
#include "CSensor.h"

class CBMA180 : CSensor
{
    public:
        CBMA180(CI2C * pI2C, uint8_t iAddress);
        virtual ~CBMA180();

        uint16_t getAccXRaw();
        uint16_t getAccYRaw();
        uint16_t getAccZRaw();

        int16_t getAccXSignedRaw();
        int16_t getAccYSignedRaw();
        int16_t getAccZSignedRaw();
        
        
        float getAccX();
        float getAccY();
        float getAccZ();

        float getAccAlpha();
        float getAccBeta();
        float getAccGamma();

        CVector getVector();

        uint16_t getAccXRawPerI2C();
        uint16_t getAccYRawPerI2C();
        uint16_t getAccZRawPerI2C();

        int16_t getAccXSignedRawPerI2C();
        int16_t getAccYSignedRawPerI2C();
        int16_t getAccZSignedRawPerI2C();        
        
        float getAccXPerI2C();
        float getAccYPerI2C();
        float getAccZPerI2C();

        float getAccAlphaPerI2C();
        float getAccBetaPerI2C();
        float getAccGammaPerI2C();

        CVector getVectorPerI2C();

        void start();
        void stop();
        void kill();
        void run();
        
        virtual int8_t getValue(float &iValue, uint8_t iChannle);

    private:
        boost::recursive_mutex  m_BMA180Mutex;
        boost::thread           m_BMA180Thread;
        bool                    m_bStop;
        CI2C *                  m_pI2C;
        uint8_t                 m_iAddress;
        uint16_t                m_iAccX;
        uint16_t                m_iAccY;
        uint16_t                m_iAccZ;
        uint8_t                 m_iBits;
        uint8_t                 m_iRange;
};

#endif // BMA180_H
