#ifndef Move_H
#define Move_H

#include "../../../CommandBase.h"
#include "WPILib.h"
#include "../../../RobotMap.h"
class Move: public CommandBase
{
public:
	Move(int, float, double);
	int angle;
	float speed;
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
