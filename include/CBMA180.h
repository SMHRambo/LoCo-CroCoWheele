#ifndef CBMA180_H
#define CBMA180_H

#include <stdint.h>
#include <boost/thread.hpp>

#include "CVector.h"
#include "CI2C.h"
#include "CSensor.h"

class CBMA180 : public CSensor
{
    public:
        /** Addiert zwei ganze Zahlen.  
         *  @param[in] a Die erste Zahl. 
         *  @param[in] b Die zweite Zahl.  
         *  @return Die Summe der beiden Zahlen a und b.  
         *  @see Addiere(double,double)  
         */
        CBMA180(CI2C * pI2C, uint8_t iAddress);
        
        /** Addiert zwei ganze Zahlen.  
         *  @param[in] a Die erste Zahl. 
         *  @param[in] b Die zweite Zahl.  
         *  @return Die Summe der beiden Zahlen a und b.  
         *  @see Addiere(double,double)  
         */
        virtual ~CBMA180();

        
        /** Addiert zwei ganze Zahlen.  
         *  @param[in] a Die erste Zahl. 
         *  @param[in] b Die zweite Zahl.  
         *  @return Die Summe der beiden Zahlen a und b.  
         *  @see Addiere(double,double)  
         */        
        uint16_t getAccXRaw();

        /** Addiert zwei ganze Zahlen.  
         *  @param[in] a Die erste Zahl. 
         *  @param[in] b Die zweite Zahl.  
         *  @return Die Summe der beiden Zahlen a und b.  
         *  @see Addiere(double,double)  
         */
        uint16_t getAccYRaw();
        
        /** Addiert zwei ganze Zahlen.  
         *  @param[in] a Die erste Zahl. 
         *  @param[in] b Die zweite Zahl.  
         *  @return Die Summe der beiden Zahlen a und b.  
         *  @see Addiere(double,double)  
         */        
        uint16_t getAccZRaw();

        
        /** Addiert zwei ganze Zahlen.  
         *  @param[in] a Die erste Zahl. 
         *  @param[in] b Die zweite Zahl.  
         *  @return Die Summe der beiden Zahlen a und b.  
         *  @see Addiere(double,double)  
         */        
        int16_t getAccXSignedRaw();
        
        /** Addiert zwei ganze Zahlen.  
         *  @param[in] a Die erste Zahl. 
         *  @param[in] b Die zweite Zahl.  
         *  @return Die Summe der beiden Zahlen a und b.  
         *  @see Addiere(double,double)  
         */        
        int16_t getAccYSignedRaw();
        
        /** Addiert zwei ganze Zahlen.  
         *  @param[in] a Die erste Zahl. 
         *  @param[in] b Die zweite Zahl.  
         *  @return Die Summe der beiden Zahlen a und b.  
         *  @see Addiere(double,double)  
         */        
        int16_t getAccZSignedRaw();
        


        /** Addiert zwei ganze Zahlen.  
         *  @param[in] a Die erste Zahl. 
         *  @param[in] b Die zweite Zahl.  
         *  @return Die Summe der beiden Zahlen a und b.  
         *  @see Addiere(double,double)  
         */        
        float getAccX();
        
        /** Addiert zwei ganze Zahlen.  
         *  @param[in] a Die erste Zahl. 
         *  @param[in] b Die zweite Zahl.  
         *  @return Die Summe der beiden Zahlen a und b.  
         *  @see Addiere(double,double)  
         */        
        float getAccY();
        
        /** Addiert zwei ganze Zahlen.  
         *  @param[in] a Die erste Zahl. 
         *  @param[in] b Die zweite Zahl.  
         *  @return Die Summe der beiden Zahlen a und b.  
         *  @see Addiere(double,double)  
         */        
        float getAccZ();

        
        /** Addiert zwei ganze Zahlen.  
         *  @param[in] a Die erste Zahl. 
         *  @param[in] b Die zweite Zahl.  
         *  @return Die Summe der beiden Zahlen a und b.  
         *  @see Addiere(double,double)  
         */        
        float getAccAlpha();
        
        /** Addiert zwei ganze Zahlen.  
         *  @param[in] a Die erste Zahl. 
         *  @param[in] b Die zweite Zahl.  
         *  @return Die Summe der beiden Zahlen a und b.  
         *  @see Addiere(double,double)  
         */        
        float getAccBeta();
        
        /** Addiert zwei ganze Zahlen.  
         *  @param[in] a Die erste Zahl. 
         *  @param[in] b Die zweite Zahl.  
         *  @return Die Summe der beiden Zahlen a und b.  
         *  @see Addiere(double,double)  
         */        
        float getAccGamma();


        /** Addiert zwei ganze Zahlen.  
         *  @param[in] a Die erste Zahl. 
         *  @param[in] b Die zweite Zahl.  
         *  @return Die Summe der beiden Zahlen a und b.  
         *  @see Addiere(double,double)  
         */        
        CVector getVector();


        /** Addiert zwei ganze Zahlen.  
         *  @param[in] a Die erste Zahl. 
         *  @param[in] b Die zweite Zahl.  
         *  @return Die Summe der beiden Zahlen a und b.  
         *  @see Addiere(double,double)  
         */        
        uint16_t getAccXRawPerI2C();

        /** Addiert zwei ganze Zahlen.  
         *  @param[in] a Die erste Zahl. 
         *  @param[in] b Die zweite Zahl.  
         *  @return Die Summe der beiden Zahlen a und b.  
         *  @see Addiere(double,double)  
         */
        uint16_t getAccYRawPerI2C();

        /** Addiert zwei ganze Zahlen.  
         *  @param[in] a Die erste Zahl. 
         *  @param[in] b Die zweite Zahl.  
         *  @return Die Summe der beiden Zahlen a und b.  
         *  @see Addiere(double,double)  
         */
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
        
        virtual bool getValue(float &iValue, uint8_t iChannle);

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
