// 
// 
// 

#include "Button.h"


bool ButtonClass::isValid(int currentTime)
{
	return currentTime - ButtonClass::timeStamp < ButtonClass::damper;
}

void ButtonClass::init()
{


}


ButtonClass Button;

