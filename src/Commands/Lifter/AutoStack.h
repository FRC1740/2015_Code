#ifndef AutoStack_H
#define AutoStack_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoStack: public CommandBase
{
public:
	AutoStack();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
