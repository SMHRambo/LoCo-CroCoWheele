/* 
 * File:   CSensor.h
 * Author: sascha
 *
 * Created on 30. August 2012, 14:42
 */

#ifndef CSENSOR_H
#define	CSENSOR_H

#include <stdint.h>

class CSensor {
public:
    CSensor();
    virtual ~CSensor();
    virtual int8_t getValue(int16_t &iValue) = 0;
private:

};

#endif	/* CSENSOR_H */

