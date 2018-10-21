// 
// 
// 

#include "OverHead.h"
#include "Button.h"

ButtonClass debugButton;

int loopTimeStamp;
int deltaTime;

void(*onDebugInterupt)();

void interruptFunction()
{
	onDebugInterupt();
}

void OverHead::init()
{
	debugButton.damper = 500;
	debugButton.timeStamp = 0;

	pinMode(overheadLedPin, OUTPUT);
	
	onDebugInterupt = OnDebugButton;

	//To simplify converting interrupt vector numbers to pin numbers you can call the function digitalPinToInterrupt, passing a pin number. It returns the appropriate interrupt number, or NOT_AN_INTERRUPT (-1).
	attachInterrupt(digitalPinToInterrupt(2), interruptFunction, RISING);
}

void OverHead::loop()
{
	delay(deltaTime);

	loopTimeStamp = millis();

	this->updateCallBack();

	int delta = millis() - loopTimeStamp;


	deltaTime = loopDelay - delta;
	deltaTime = deltaTime < 0 ? 0 : deltaTime;

	if (debugEnabled)
	{
		Serial.println(deltaTime);
	}

	if (deltaTime == 0)
	{
		if (!isOverHead)
		{
			OnOverhead(true);
		}
	}
	else if (isOverHead)
	{
		OnOverhead(false);
	}
}

void OverHead::OnDebugButton()
{
	if (debugButton.isValid(millis()))
	{
		return;
	}

	debugButton.timeStamp = millis();
	debugEnabled = !debugEnabled;
	OnOverhead(!isOverHead);
}

void OverHead::OnOverhead(bool state)
{
	isOverHead = state;
	state = debugEnabled ? state : false;
	digitalWrite(overheadLedPin, (state ? HIGH : LOW));
}

