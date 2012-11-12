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
    /** Erzeugt ein Objekt der Klasse CActor.
     */
    CActor();
    
    /** Löscht ein Objekt der Klasse CActor.
     */
    virtual ~CActor();
    
    /** Gibt den Wert iValue an den Datenkanal iChannel weiter.  
     *  @param[in] iValue Wert der übergeben werden soll. 
     *  @param[in] iChannle Datenkanal an dem der Wert iValue übergeben werden soll.  
     *  @return Gibt zurück ob der Wert iValue in den Datenkanal iChannle übergeben werden konnte, bzw. ob es den aufgerufenen Datenkanal gibt.  
     */
    virtual bool setValue(float iValue, uint8_t iChannle) = 0;
private:

};

#endif	/* CACTOR_H */

