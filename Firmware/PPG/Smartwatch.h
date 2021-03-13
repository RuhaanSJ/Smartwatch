/*
 FILENAME:	Smartwatch.h
 AUTHOR:	Orlando S. Hoilett
 EMAIL:		orlandohoilett@gmail.com
 
 
 Please see .cpp file for extended descriptions, instructions, and version updates
 
 
 */


#ifndef Smartwatch_h
#define Smartwatch_h


//Standard Arduino Libraries
#include <Arduino.h>

//Custom External Libraries
#include "AD524X.h"


class Smartwatch
{
	
private:
	
	//potentiometer to control gain of TIA and bandpass filters
	AD524X ad5242;
	
	//Gain settings for digital potentiometers
	uint8_t R_ledCurrent;
	uint8_t R_tiaGain;
	uint8_t R_ppgGain;
	
	//true = ON, false = OFF
	bool ledState;
	
	
public:
	
	Smartwatch(); //must be called before setup in .ino code
	void begin(); //must be called in setup in .ino code
	
	
	//Control LED
	void turnLEDOn();
	void turnLEDOff();
	bool getLEDStatus() const;
	void setLEDCurrent(uint8_t val);
	uint8_t getLEDCurrent() const;
	void balanceLEDCurrent();
	
	
	//Amplifier gain control for TIA
	void setTIAGain(uint8_t gain);
	uint8_t getTIAGain() const;
	void balanceTIAGain();
	
	
	//Amplifier gain control for Bandpass filter
	void setPPGGain(uint8_t gain);
	uint8_t getPPGGain() const;
	
	
	//Read voltage of PPG circuit
	uint16_t getTIA() const;
	uint16_t getPPG() const; //bandpass filters
	
	
};



#endif /* Smartwatch_h */