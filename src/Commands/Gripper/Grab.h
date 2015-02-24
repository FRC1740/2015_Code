#ifndef GRAB_H
#define GRAB_H

#include "../../CommandBase.h"
#include "WPILib.h"

class Grab: public CommandBase
{
public:
	Grab();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
