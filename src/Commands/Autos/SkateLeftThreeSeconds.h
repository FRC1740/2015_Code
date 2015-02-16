#ifndef SkateLeftThreeSeconds_H
#define SkateLeftThreeSeconds_H

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
