#ifndef CITG3200_H
#define CITG3200_H

#include <stdint.h>
#include <boost/thread.hpp>

#include "CVector.h"
#include "CI2C.h"
#include "CSensor.h"

class CITG3200 : public CSensor
{
    public:
        CITG3200(CI2C * pI2C, uint8_t iAddress);
        virtual ~CITG3200();
        
        CLK getClockSource();
        void setClockSource(CLK CLKsource);
        
        bool isXgyroStandby();
        bool isYgyroStandby();
        bool isZgyroStandby();
        void setXgyroStandby(bool bStatus);
        void setYgyroStandby(bool bStatus);
        void setZgyroStandby(bool bStatus);
        
        uint8_t getSampleRateDiv();
        void setSampleRateDiv(uint8_t SampleRateDiv);
        FSR getFSRange();
        void setFSRange(FSR Range);
        FBW getFilterBW();
        void setFilterBW(FBW FilterBW);
        
        void reset();
        bool isSleepMode();
        void setSleepMode(bool bState);
        
        bool isITGReady();
        bool isRawDataReady();

        uint16_t getGyroXRaw();
        uint16_t getGyroYRaw();
        uint16_t getGyroZRaw();

        float getGyroXinDeg();
        float getGyroYinDeg();
        float getGyroZinDeg();
        
        float getGyroXinRad();
        float getGyroYinRad();
        float getGyroZinRad();       

        uint16_t getGyroXRawPerI2C();
        uint16_t getGyroYRawPerI2C();
        uint16_t getGyroZRawPerI2C();

        float getGyroXinRadPerI2C();
        float getGyroYinRadPerI2C();
        float getGyroZinRadPerI2C();

        void start();
        void stop();
        void kill();
        void run();

        virtual bool getValue(float &iValue, uint8_t iChannle);
        
        enum CLK {IntOSC, PPL_X, PPL_Y, PPL_Z, PPL_Ext_32KHz, PPL_Ext_19MHz};
        enum FSR {_250, _500, _1000, _2000};
        enum FBW {BW256_8SR, BW188_1SR, BW98_1SR, BW42_1SR, BW20_1SR, BW10_1SR, BW5_1SR};
        
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
