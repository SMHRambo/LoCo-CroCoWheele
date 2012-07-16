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
        CI2C * pI2C = new CI2C("/dev/i2c-1");
        
        CBMA180 * pBMA180 = new CBMA180(pI2C, 0b1000000);
        
        while(true)
        {
            std::cout << "Start reading i2c" << std::endl;
            std::cout << pBMA180->getAccXPerI2C() << std::endl;
            std::cout << "Finished reading i2c" << std::endl;
            sleep(1000);
        }

        return 0;    
    }
    catch(...)
    {
        
    }
}

