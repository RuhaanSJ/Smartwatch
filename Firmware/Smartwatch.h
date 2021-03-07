/*
    Abbreviations:
    1) Photoplethysmography- proces of measuring changes in volume in light
                             Used to measure heart rate, respiration and blood oxygen
                             by measuring changes in volume in the blood vessels
    2) BPF
    3) I2C
*/

#ifndef Smartwatch_h
#define Smartwatch_h

//Standard Arduino Libraries
#include <Arduino.h>

//Custom External Libraries
#include <AD524X.h>

class Smartwatch
{

    private:

        AD524X ad5242; // potentiometer to control gain of TIA and Bandpass filter

        uint8_t R_ledCurrent;
        uint8_t R_tiaGain;
        uint8_t R_ppgGain;

    public:

        Smartwatch();

        //control LED
        void turnLEDOn() const;

        //
        void turnLEDOff() const;
        
        void setLEDCurrent();
        uint8_t getLEDCurrent() const;
        
        void setTIAGain();
        uint8_t getTIAGain() const;

        void setPPGGain();
        uint8_t getPPGGain() const;
        
        uint16_t getTIA();
        unint16_t getPPG();
};

#endif