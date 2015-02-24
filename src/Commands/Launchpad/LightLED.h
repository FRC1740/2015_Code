#ifndef LIGHTLED_H
#define LIGHTLED_H

#include "../../CommandBase.h"
#include "WPILib.h"

class LightLED: public CommandBase
{
	public:
		LightLED();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};

#endif
