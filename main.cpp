/* 
 * File:   main.cpp
 * Author: sascha
 *
 * Created on 14. Juli 2012, 01:44
 */

#include <cstdlib>
#include <iostream>

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
        CI2C * pI2C = new CI2C("/dev/i2c-3");
        
        CBMA180 * pBMA180 = new CBMA180(pI2C, 0x41);
        
        CITG3200 * pITG3200 = new CITG3200(pI2C, 0x11);
        
        CPWMDriver * pPWMDriver = new CPWMDriver(pI2C, 0xA0);
        
        CRPMeter * pRPMeterL = new CRPMeter(pI2C, 0x20);
        
        CRPMeter * pRPMeterR = new CRPMeter(pI2C, 0x22);
        
        CPIDRegler * pPIDReglerL = new CPIDRegler(pRPMeterL, 0, pPWMDriver, 0);
                
        CPIDRegler * pPIDReglerR = new CPIDRegler(pRPMeterR, 0, pPWMDriver, 1);
        
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

