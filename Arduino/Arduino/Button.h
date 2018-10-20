// Button.h

#ifndef _BUTTON_h
#define _BUTTON_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class ButtonClass
{
protected:


public:
	int damper;
	int timeStamp;
	void init();
	bool isValid(int);
};

extern ButtonClass Button;

#endif

