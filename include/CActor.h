/* 
 * File:   CActor.h
 * Author: sascha
 *
 * Created on 30. August 2012, 14:48
 */

#ifndef CACTOR_H
#define	CACTOR_H

#include <stdint.h>

class CActor {
public:
    CActor();
    virtual ~CActor();
    virtual bool setValue(float iValue, uint8_t iChannle) = 0;
private:

};

#endif	/* CACTOR_H */

