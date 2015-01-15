#ifndef SetTilt_H
#define SetTilt_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Subsystems/Lifter.h"

class SetTilt: public CommandBase
{
public:
	SetTilt();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
