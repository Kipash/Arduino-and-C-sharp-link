// 
// 
// 

#include "OverHead.h"
#include "Button.h"



ButtonClass debugButton;

int loopTimeStamp = 0;
int loopDelay = 50;
bool isOverHead = false;

int overheadLedPin = 13;
int deltaTime = 0;

bool debugEnabled = true;

void OverheadClass::init()
{
	debugButton.damper = 500;
	debugButton.timeStamp = 0;

	pinMode(overheadLedPin, OUTPUT);
	
	
	attachInterrupt(0, callBack, RISING);

}

void callBack()
{
	//stuff
}

void OverheadClass::loop()
{
	delay(deltaTime);

	loopTimeStamp = millis();

	OverheadClass::updateCallBack();

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

void OverheadClass::OnDebugButton()
{
	if (debugButton.isValid(millis()))
	{
		return;
	}

	debugButton.timeStamp = millis();
	debugEnabled = !debugEnabled;
	OnOverhead(!isOverHead);
}
void OverheadClass::OnOverhead(bool state)
{
	isOverHead = state;
	state = debugEnabled ? state : false;
	digitalWrite(overheadLedPin, (state ? HIGH : LOW));
}


OverheadClass OverHead;

