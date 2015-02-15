#ifndef MoveToLevel_H
#define MoveToLevel_H

#include "../CommandBase.h"
#include "WPILib.h"

#include <math.h>

#define MAX_ENCODER_VALUE 800  // TODO make this properly reflect the top level

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
