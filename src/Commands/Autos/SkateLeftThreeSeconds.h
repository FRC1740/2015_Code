#ifndef SKATELEFTTHREESECONDS_H
#define SKATELEFTTHREESECONDS_H

#include "../../CommandBase.h"
#include "WPILib.h"

class SkateLeftThreeSeconds: public CommandBase
{
public:
	SkateLeftThreeSeconds();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
