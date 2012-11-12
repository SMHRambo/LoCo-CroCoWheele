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
    /** Erzeugt ein Objekt der Klasse CSensor.
     */
    CSensor();
    
    /** Löscht ein Objekt der Klasse CActor.  
     */
    virtual ~CSensor();
    
    /** Gibt den Wert iValue von dem Datenkanal iChannel zurück.  
     *  @param[out] iValue Wert der zurückgegeben wird. 
     *  @param[in] iChannle Datenkanal von dem der Wert iValue übergeben werden soll.  
     *  @return Gibt zurück ob der Wert iValue von dem Datenkanal iChannle übergeben werden konnte, bzw. ob es den aufgerufenen Datenkanal gibt.  
     */
    virtual bool getValue(float &iValue, uint8_t iChannle) = 0;
private:

};

#endif	/* CSENSOR_H */

