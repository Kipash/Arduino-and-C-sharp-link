// OverHead.h

#ifndef _OVERHEAD_h
#define _OVERHEAD_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class OverheadClass
{

	 protected:
		int loopTimeStamp;
		int deltaTime;

	 public:
		void (*updateCallBack)();
		bool isOverHead;
		int loopDelay;
		int overheadLedPin;
		bool debugEnabled;
		void OnOverhead(bool);
		void OnDebugButton();
		
		void init();
		void loop();
};

extern OverheadClass OverHead;

#endif

