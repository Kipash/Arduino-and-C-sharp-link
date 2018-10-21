/*
 Name:		Arduino.ino
 Created:	20-Oct-18 21:02:14
 Author:	Kip
*/

//References

#include "OverHead.h"
#include "Button.h"

//Main loop variables

OverHead overhead;

void setup()
{
	Start();
	
	overhead.init();
	
	overhead.debugEnabled = true;
	overhead.loopDelay = 50;
	overhead.overheadLedPin = 13;
	overhead.updateCallBack = Update;
}

void loop()
{
	overhead.loop();
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
	Serial.println("Heyoooo");
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