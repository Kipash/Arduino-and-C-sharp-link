// OverHead.h

#ifndef _OVERHEAD_h
#define _OVERHEAD_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class OverHead
{
	 protected:
		//int loopTimeStamp;
		//int deltaTime;

	 public:
		int loopDelay = 50;
		bool isOverHead = false;
		int overheadLedPin = 13;
		bool debugEnabled = true;

		void OnOverhead(bool);
		void OnDebugButton();
		void init();
		void loop();
		void (*updateCallBack)();
};

extern OverHead;

#endif

