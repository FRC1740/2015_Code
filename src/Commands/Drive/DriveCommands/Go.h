#ifndef Go_H
#define Go_H

#include "../../../CommandBase.h"
#include "WPILib.h"

class Go: public CommandBase
{
public:
	Go(int, float, float, float, float);
	float front_right, rear_right, front_left, rear_left;
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
