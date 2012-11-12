/* 
 * File:   main.cpp
 * Author: sascha
 *
 * Created on 14. Juli 2012, 01:44
 */

#include <cstdlib>
#include <iostream>
#include <unistd.h>

//Add class libs for i2c Bus, BMA180 Sensor, ITG3200 Sensor, PWMDriver, RPMeter Sensor and PIDRegler
#include "include/CI2C.h"
#include "include/CBMA180.h"
#include "include/CPWMDriver.h"
#include "include/CITG3200.h"
#include "include/CRPMeter.h"
#include "include/CPIDRegler.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv)
{
    try
    {
        
        //Create a i2c bus object to handel communiation for sensors and actors
        CI2C * pI2C = new CI2C("/dev/i2c-3");
        
        //Creare a BMA180 sensor object to handel BMA180 sensor 
        CBMA180 * pBMA180 = new CBMA180(pI2C, 0x40);
        
        //Creare a ITG3200 sensor object to handel ITG3200 sensor
        CITG3200 * pITG3200 = new CITG3200(pI2C, 0x69);
        
        //Creare a PWMDriver object to handel PWMDriver
        CPWMDriver * pPWMDriver = new CPWMDriver(pI2C, 0xA0);
        
        //Creare a RPMeter sensor object to handel RPMeter sensor (Left motor)
        CRPMeter * pRPMeterL = new CRPMeter(pI2C, 0x20);
        
        //Creare a RPMeter sensor object to handel RPMeter sensor (Right motor)
        CRPMeter * pRPMeterR = new CRPMeter(pI2C, 0x22);
        
        //Creare a PIDRegler object to handel PID Regler(Left motor)
        CPIDRegler * pPIDReglerL = new CPIDRegler(pRPMeterL, 0, pPWMDriver, 0);
        
        //Creare a PIDRegler object to handel PID Regler(Right motor)
        CPIDRegler * pPIDReglerR = new CPIDRegler(pRPMeterR, 0, pPWMDriver, 1);
        
        //Start all objekts(Every object has a thread, you can activate the thread to receive and update the data or you can to it manually)
        //pBMA180->start();
        //pITG3200->start();
        //pRPMeterL->start();
        //pRPMeterR->start();
        //pPIDReglerL->start();
        //pPIDReglerR->start();
        
        while(true)
        {
            std::cout << "X-Achse: " << pBMA180->getAccXRawPerI2C() << std::endl;
            usleep( 100000 );
            std::cout << "Y-Achse: " << pBMA180->getAccYRawPerI2C() << std::endl;
            usleep( 100000 );
            std::cout << "Z-Achse: " << pBMA180->getAccZRawPerI2C() << std::endl;
            usleep( 100000 );
        }

        return 0;    
    }
    catch(...)
    {
        
    }
}

