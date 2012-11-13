#ifndef CBMA180_H
#define CBMA180_H

#include <stdint.h>
#include <boost/thread.hpp>
#include <bitset>
#include <string>

#include "CVector.h"
#include "CI2C.h"
#include "CSensor.h"

class CBMA180 : public CSensor
{
    public:
        /** Erzeugt ein Objekt der Klasse CBMA180.
         * Der Konstruktor erwartet als Parameter die i2c Adresse des Sensors und ein i2c Bus Objekt über den der Sensor ansgeschlossen ist.
         * @param[in] pI2C Der i2c Bus über dem der Sensor angeschlossen ist. 
         * @param[in] iAddress Die Adresse des Sensors auf dem i2c Bus.    
         */
        CBMA180(CI2C * pI2C, uint8_t iAddress);
        
        /** Löscht ein Objekt der Klasse CBMA180.
         */
        virtual ~CBMA180();

        
        /** Gibt die Membervariable m_iAccX zurück.  
         * Diese Funktion gibt den Beschleunigungswert der X-Achse des Sensors im RAW Format zurück.
         * Der Wert wird mit Hilfe des internen Threads oder durch aufrufen der Funktion run() aktualisiert.
         * @return Gibt den X-Achsen.Beschleunigung im RAW Format zurück die im Objekt gespeichert wurde.
         * @see getAccYRaw()
         * @see getAccZRaw();
         */        
        uint16_t getAccXRaw();

        /** Gibt die Membervariable m_iAccY zurück.  
         * Diese Funktion gibt den Beschleunigungswert der Y-Achse des Sensors im RAW Format zurück.
         * Der Wert wird mit Hilfe des internen Threads oder durch aufrufen der Funktion run() aktualisiert.
         * @return Gibt den Y-Achsen-Beschleunigung im RAW Format zurück die im Objekt gespeichert wurde.
         * @see getAccXRaw()
         * @see getAccZRaw();
         */  
        uint16_t getAccYRaw();
        
        /** Gibt die Membervariable m_iAccZ zurück.  
         * Diese Funktion gibt den Beschleunigungswert der Z-Achse des Sensors im RAW Format zurück.
         * Der Wert wird mit Hilfe des internen Threads oder durch aufrufen der Funktion run() aktualisiert.
         * @return Gibt den Z-Achsen-Beschleunigung im RAW Format zurück die im Objekt gespeichert wurde.
         * @see getAccXRaw()
         * @see getAccYRaw();
         */       
        uint16_t getAccZRaw();

        
        /** Gibt die Membervariable m_iAccX mit Vorzeichen zurück.  
         * Diese Funktion gibt den Beschleunigungswert der X-Achse des Sensors im RAW Format mit Vorzeichen zurück.
         * Der Wert wird mit Hilfe des internen Threads oder durch aufrufen der Funktion run() aktualisiert.
         * @return Gibt den X-Achsen-Beschleunigung im RAW Format mit Vorzeichen zurück die im Objekt gespeichert wurde.
         * @see getAccYRaw()
         * @see getAccZRaw();
         */          
        int16_t getAccXSignedRaw();
        
        /** Gibt die Membervariable m_iAccY mit Vorzeichen zurück.  
         * Diese Funktion gibt den Beschleunigungswert der Y-Achse des Sensors im RAW Format mit Vorzeichen zurück.
         * Der Wert wird mit Hilfe des internen Threads oder durch aufrufen der Funktion run() aktualisiert.
         * @return Gibt den Y-Achsen-Beschleunigung im RAW Format mit Vorzeichen zurück die im Objekt gespeichert wurde.
         * @see getAccXRaw()
         * @see getAccZRaw();
         */        
        int16_t getAccYSignedRaw();
        
        /** Gibt die Membervariable m_iAccZ mit Vorzeichen zurück.  
         * Diese Funktion gibt den Beschleunigungswert der Z-Achse des Sensors im RAW Format mit Vorzeichen zurück.
         * Der Wert wird mit Hilfe des internen Threads oder durch aufrufen der Funktion run() aktualisiert.
         * @return Gibt den Z-Achsen-Beschleunigung im RAW Format mit Vorzeichen zurück die im Objekt gespeichert wurde.
         * @see getAccXRaw()
         * @see getAccYRaw();
         */            
        int16_t getAccZSignedRaw();
        


        /** Gibt die Membervariable m_iAccX als float in der richtigen Sklaierung zurück.  
         * Diese Funktion gibt den Beschleunigungswert der X-Achse des Sensors als float in der richtigen Sklaierung zurück.
         * Der Wert wird mit Hilfe des internen Threads oder durch aufrufen der Funktion run() aktualisiert.
         * @return Gibt den X-Achsen-Beschleunigung als float in der richtigen Sklaierung zurück die im Objekt gespeichert wurde.
         * @see getAccYRaw()
         * @see getAccZRaw();
         */        
        float getAccX();
        
        /** Gibt die Membervariable m_iAccY als float in der richtigen Sklaierung zurück.  
         * Diese Funktion gibt den Beschleunigungswert der Y-Achse des Sensors als float in der richtigen Sklaierung zurück.
         * Der Wert wird mit Hilfe des internen Threads oder durch aufrufen der Funktion run() aktualisiert.
         * @return Gibt den Y-Achsen-Beschleunigung als float in der richtigen Sklaierung zurück die im Objekt gespeichert wurde.
         * @see getAccXRaw()
         * @see getAccZRaw();
         */        
        float getAccY();
        
        /** Gibt die Membervariable m_iAccZ als float in der richtigen Sklaierung zurück.  
         * Diese Funktion gibt den Beschleungungswert der Z-Achse des Sensors als float in der richtigen Sklaierung zurück.
         * Der Wert wird mit Hilfe des internen Threads oder durch aufrufen der Funktion run() aktualisiert.
         * @return Gibt den Z-Achsen-Beschleunigung als float in der richtigen Sklaierung zurück die im Objekt gespeichert wurde.
         * @see getAccXRaw()
         * @see getAccYRaw();
         */        
        float getAccZ();

        
        /** Gibt den Winkel Alpha zurück.  
         * Diese Funktion gibt den Winkel des Beschleunigungsvektor in Relation zur X-Achse zurück.
         * Der Wert wird mit Hilfe des internen Threads oder durch aufrufen der Funktion run() aktualisiert.
         * @return Der Winkel des Beschleunigungsvektors zur X-Achse.  
         * @see getAccBeta()
         * @see getAccGamma();  
         */        
        float getAccAlpha();
        
        /** Gibt den Winkel Beta zurück.  
         * Diese Funktion gibt den Winkel des Beschleunigungsvektor in Relation zur Y-Achse zurück.
         * Der Wert wird mit Hilfe des internen Threads oder durch aufrufen der Funktion run() aktualisiert.
         * @return Der Winkel des Beschleunigungsvektors zur Y-Achse.  
         * @see getAccAlpha()
         * @see getAccGamma();  
         */       
        float getAccBeta();
        
        /** Gibt den Winkel Gamma zurück.  
         * Diese Funktion gibt den Winkel des Beschleunigungsvektor in Relation zur Z-Achse zurück.
         * Der Wert wird mit Hilfe des internen Threads oder durch aufrufen der Funktion run() aktualisiert.
         * @return Der Winkel des Beschleunigungsvektors zur Z-Achse.  
         * @see getAccAlpha()
         * @see getAccBeta();  
         */        
        float getAccGamma();


        /** Gibt einen Objekt des Typs CVector zurück.  
         * Diese Funktion gibt einen Vektor zurück der alle Beschleunigungswerte des Sensors enthält zurück.
         * Der Wert wird mit Hilfe des internen Threads oder durch aufrufen der Funktion run() aktualisiert.
         * @return Der Beschleunigungsvektor des Sensors.
         */        
        CVector getVector();


        /** Gibt die die X-Achsen Beschleunigung des Sensors zurück.  
         * Diese Funktion gibt den Beschleunigungswert der X-Achse des Sensors im RAW Format zurück.
         * Bei dieser Funktion wird der Sensor über I2C angesprochen und der Wert frisch ausgelesen.
         * @return Gibt den X-Achsen.Beschleunigung im RAW Format zurück.
         * @see getAccYRawPerI2C()
         * @see getAccZRawPerI2C();
         */        
        uint16_t getAccXRawPerI2C();

        /** Gibt die die Y-Achsen Beschleunigung des Sensors zurück.  
         * Diese Funktion gibt den Beschleunigungswert der Y-Achse des Sensors im RAW Format zurück.
         * Bei dieser Funktion wird der Sensor über I2C angesprochen und der Wert frisch ausgelesen.
         * @return Gibt den Y-Achsen.Beschleunigung im RAW Format zurück.
         * @see getAccXRawPerI2C()
         * @see getAccZRawPerI2C();
         */
        uint16_t getAccYRawPerI2C();

        /** Gibt die die Z-Achsen Beschleunigung des Sensors zurück.  
         * Diese Funktion gibt den Beschleunigungswert der Z-Achse des Sensors im RAW Format zurück.
         * Bei dieser Funktion wird der Sensor über I2C angesprochen und der Wert frisch ausgelesen.
         * @return Gibt den Z-Achsen.Beschleunigung im RAW Format zurück.
         * @see getAccXRawPerI2C()
         * @see getAccYRawPerI2C();
         */
        uint16_t getAccZRawPerI2C();

        
        /** Gibt die die Z-Achsen Beschleunigung des Sensors zurück.  
         * Diese Funktion gibt den Beschleunigungswert der Z-Achse des Sensors im RAW Format zurück.
         * Bei dieser Funktion wird der Sensor über I2C angesprochen und der Wert frisch ausgelesen.
         * @return Gibt den Z-Achsen.Beschleunigung im RAW Format zurück.
         * @see getAccXRawPerI2C()
         * @see getAccYRawPerI2C();
         */
        int16_t getAccXSignedRawPerI2C();
        int16_t getAccYSignedRawPerI2C();
        int16_t getAccZSignedRawPerI2C();        
        
        float getAccXPerI2C();
        float getAccYPerI2C();
        float getAccZPerI2C();

        float getAccAlphaPerI2C();
        float getAccBetaPerI2C();
        float getAccGammaPerI2C();

        CVector getVectorPerI2C();

        void start();
        void stop();
        void kill();
        void run();
        
        virtual bool getValue(float &iValue, uint8_t iChannle);

    private:
        boost::recursive_mutex  m_BMA180Mutex;
        boost::thread           m_BMA180Thread;
        bool                    m_bStop;
        CI2C *                  m_pI2C;
        uint8_t                 m_iAddress;
        uint16_t                m_iAccX;
        uint16_t                m_iAccY;
        uint16_t                m_iAccZ;
        uint8_t                 m_iBits;
        uint8_t                 m_iRange;
};

#endif // BMA180_H
