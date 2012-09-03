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
    virtual bool getValue(float &iValue, uint8_t iChannle) = 0;
private:

};

#endif	/* CSENSOR_H */

