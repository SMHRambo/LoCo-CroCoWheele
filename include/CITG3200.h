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
        
        enum CLK {IntOSC, PPL_X, PPL_Y, PPL_Z, PPL_Ext_32KHz, PPL_Ext_19MHz};
        enum FSR {_250, _500, _1000, _2000};
        enum FBW {BW256_8SR, BW188_1SR, BW98_1SR, BW42_1SR, BW20_1SR, BW10_1SR, BW5_1SR};
    
        CITG3200(CI2C * pI2C, uint8_t iAddress);
        virtual ~CITG3200();
        
        enum CLK getClockSource();
        void setClockSource(CLK CLKsource);
        
        bool isXgyroStandby();
        bool isYgyroStandby();
        bool isZgyroStandby();
        void setXgyroStandby(bool bStatus);
        void setYgyroStandby(bool bStatus);
        void setZgyroStandby(bool bStatus);
        
        uint8_t getSampleRateDiv();
        void setSampleRateDiv(uint8_t iSampleRateDiv);
        FSR getFSRange();
        void setFSRange(FSR Range);
        FBW getFilterBW();
        void setFilterBW(FBW FilterBW);
        
        void reset();
        bool isSleepMode();
        void setSleepMode(bool bState);
        
        bool isITGReady();
        bool isRawDataReady();
        
        int16_t getOffsetX();
        int16_t getOffsetY();
        int16_t getOffsetZ();
        
        void setOffsetX(int16_t iOffsetX);
        void setOffsetY(int16_t iOffsetY);
        void setOffsetZ(int16_t iOffsetZ);
        
        float getScaleX();
        float getScaleY();
        float getScaleZ();
        
        void setScaleX(float iScaleX);
        void setScaleY(float iScaleY);
        void setScaleZ(float iScaleZ);

        int16_t getGyroXRaw();
        int16_t getGyroYRaw();
        int16_t getGyroZRaw();

        float getGyroXinDeg();
        float getGyroYinDeg();
        float getGyroZinDeg();
        
        float getGyroXinRad();
        float getGyroYinRad();
        float getGyroZinRad();       

        int16_t getGyroXRawPerI2C();
        int16_t getGyroYRawPerI2C();
        int16_t getGyroZRawPerI2C();

        float getGyroXinDegPerI2C();
        float getGyroYinDegPerI2C();
        float getGyroZinDegPerI2C(); 
        
        float getGyroXinRadPerI2C();
        float getGyroYinRadPerI2C();
        float getGyroZinRadPerI2C();       

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
        int16_t                m_iGyroX;
        int16_t                m_iGyroY;
        int16_t                m_iGyroZ;
        int16_t                 m_iOffsetX;
        int16_t                 m_iOffsetY;
        int16_t                 m_iOffsetZ;
        float                   m_iScaleX;
        float                   m_iScaleY;
        float                   m_iScaleZ;
};

#endif // ITG3200_H
