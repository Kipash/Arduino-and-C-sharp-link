/*
 Name:		Sketch1.ino
 Created:	20-Oct-18 21:02:14
 Author:	Kip
*/

//References

#include "Button.h"
#include "Button.h"

//Main loop variables

ButtonClass debugButton;

int timeStamp = 0;
int loopDelay = 50;
bool isOverHead = false;

int overheadLedPin = 13;
int deltaTime = 0;

bool debugEnabled = true;
bool overhead = false;

void setup()
{
	Start();

	debugButton.damper = 500;
	debugButton.timeStamp = 0;

	pinMode(overheadLedPin, OUTPUT);
	attachInterrupt(0, OnDebugButoon, RISING);
}

void loop()
{
	delay(deltaTime);

	timeStamp = millis();

	Update();

	int delta = millis() - timeStamp;


	deltaTime = loopDelay - delta;
	deltaTime = deltaTime < 0 ? 0 : deltaTime;

	Serial.println(deltaTime);

	if (deltaTime == 0)
	{
		if (!isOverHead)
		{
			isOverHead = true;
			OnOverhead(true);
		}
	}
	else if (isOverHead)
	{
		isOverHead = false;
		OnOverhead(false);
	}
}

void OnDebugButoon()
{
	if (debugButton.isValid(millis()))
	{
		return;
	}

	debugButton.timeStamp = millis();
	debugEnabled = !debugEnabled;
	OnOverhead(overhead);
}

void OnOverhead(bool state)
{
	overhead = state;
	state = debugEnabled ? state : false;
	digitalWrite(overheadLedPin, (state ? HIGH : LOW));
}

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ----

int testLedPin = 12;


ButtonClass testButton;

void Start()
{
	Serial.begin(9600);

	pinMode(testLedPin, OUTPUT);
	attachInterrupt(1, OnTestButton, RISING);

	testButton.damper = 500;
	testButton.timeStamp = 0;
}

void Update()
{

}

void SetTestLed(bool state)
{
	digitalWrite(testLedPin, (state ? HIGH : LOW));
}


bool ledState;
void OnTestButton()
{
	if (testButton.isValid(millis()))
	{
		return;
	}

	testButton.timeStamp = millis();
	Serial.println("Test button");

	ledState = !ledState;
	SetTestLed(ledState);
}