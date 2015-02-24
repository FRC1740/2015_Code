#ifndef MOVETOLEVEL_H
#define MOVETOLEVEL_H

#include "../../CommandBase.h"
#include "WPILib.h"

#include <math.h>

#define MAX_ENCODER_VALUE 1000

class MoveToLevel: public CommandBase
{
private:
	int Setpoint;
	int direction;
public:
	MoveToLevel(int);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
