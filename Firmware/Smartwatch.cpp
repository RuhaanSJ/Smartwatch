#include "Smartwatch.h"

const uint8_t ledPin = 29;
const uint8_t ppgPin = A7;
const uint8_t tiaPIN = A6;
Smartwatch::Smartwatch()
{

}

void Smartwatch::begin()
{   
    pinMode(ledPin, OUTPUT);
    analogReadResolution(12); //0 and 4095
}

void Smartwatch::turnLEDOn() const
{
    digitalWrite(ledPin, HIGH);
}

void Smartwatch::turnLEDOff() const
{
    digitalWrite(ledPin, LOW);
}

void Smartwatch::setLEDCurrent();
{
    Wire.beginTransmission(44); // transmit to device #44 (0x2c)
                              // device address is specified in datasheet
    Wire.write(byte(0x00));            // sends instruction byte  
    Wire.write(val);             // sends potentiometer value byte  
    Wire.endTransmission();     // stop transmitting

    val++;        // increment value
    if(val == 64) // if reached 64th position (max)
    {
     val = 0;    // start over from lowest value
    }
  delay(500);
}
uint8_t Smartwatch::getLEDCurrent() const;

void Smartwatch::setTIAGain();
uint8_t Smartwatch::getTIAGain() const;

void Smartwatch::setBPFGAin();
uint8_t Smartwatch::getBPFGain() const;

uint16_t Smartwatch::getTIA() const
{
    return analogRead(tiaPIN);
}

uint16_t Smartwatch::getPPG() const
{
    return analogRead(ppgPin); 
}

