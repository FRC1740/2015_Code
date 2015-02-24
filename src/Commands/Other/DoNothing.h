#ifndef WAIT_H
#define WAIT_H

#include "../../CommandBase.h"
#include "WPILib.h"

class DoNothing: public CommandBase
{
public:
	DoNothing(int);
	int timer;
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
