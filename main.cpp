/* 
 * File:   main.cpp
 * Author: sascha
 *
 * Created on 14. Juli 2012, 01:44
 */

#include <cstdlib>
#include <iostream>

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
        
        //Creare a BMA180 sensor object to handel BMA180 Sensor 
        CBMA180 * pBMA180 = new CBMA180(pI2C, 0x41);
        
        //Creare a ITG3200 sensor object to handel ITG3200 Sensor
        CITG3200 * pITG3200 = new CITG3200(pI2C, 0x11);
        
        //Creare a PWMDriver object to handel PWMDriver
        CPWMDriver * pPWMDriver = new CPWMDriver(pI2C, 0xA0);
        
        //Creare a RPMeter sensor object to handel RPMeter Sensor (Left motor)
        CRPMeter * pRPMeterL = new CRPMeter(pI2C, 0x20);
        
        //Creare a RPMeter sensor object to handel RPMeter Sensor (Right motor)
        CRPMeter * pRPMeterR = new CRPMeter(pI2C, 0x22);
        
        //Creare a PIDRegler object to handel PID Regler(Left motor)
        CPIDRegler * pPIDReglerL = new CPIDRegler(pRPMeterL, 0, pPWMDriver, 0);
        
        //Creare a PIDRegler object to handel PID Regler(Right motor)
        CPIDRegler * pPIDReglerR = new CPIDRegler(pRPMeterR, 0, pPWMDriver, 1);
        
        //Start all objekts(Every object has a thread, you can activate the thread to receive or update the data or you can to it manually)
        pBMA180->run();
        pITG3200->run();
        pRPMeterL->run();
        pRPMeterR->run();
        pPIDReglerL->run();
        pPIDReglerR->run();
        
        while(true)
        {
            
        }

        return 0;    
    }
    catch(...)
    {
        
    }
}

