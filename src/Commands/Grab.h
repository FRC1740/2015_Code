#ifndef Grab_H
#define Grab_H

#include "../CommandBase.h"
#include "WPILib.h"

class Grab: public CommandBase
{
public:
	Grab(DataLogger *);
	DataLogger *l;
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
