#ifndef Toggle_H
#define Toggle_H

#include "../../CommandBase.h"
#include "WPILib.h"

class Toggle: public CommandBase
{
public:
	Toggle();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
