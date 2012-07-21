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
        
        while(true)
        {
            //std::cout << pBMA180->getAccXRawPerI2C() << std::endl;
            pBMA180->run();
        }

        return 0;    
    }
    catch(...)
    {
        
    }
}

