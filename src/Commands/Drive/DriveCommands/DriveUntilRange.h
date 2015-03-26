#ifndef DriveUntilRange_H
#define DriveUntilRange_H

#include "../../../CommandBase.h"
#include "WPILib.h"

class DriveUntilRange: public CommandBase
{
public:
	DriveUntilRange(int, float);
	int range;
	float speed;
	int direction;
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
