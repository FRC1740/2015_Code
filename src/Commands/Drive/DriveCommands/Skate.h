#ifndef SKATE_H
#define SKATE_H

#include "../../../CommandBase.h"
#include "WPILib.h"

class Skate: public CommandBase
{
public:
	Skate(int, int);
	int selfdirection;
	int selftime;
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
