#ifndef StandardTankDrive_H
#define StandardTankDrive_H

#include "../../CommandBase.h"
#include "WPILib.h"

class StandardTankDrive: public CommandBase
{
public:
	StandardTankDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
