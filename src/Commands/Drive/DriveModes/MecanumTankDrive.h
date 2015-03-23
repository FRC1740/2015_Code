#ifndef MECANUMTANKDRIVE_H
#define MECANUMTANKDRIVE_H

#include "../../../CommandBase.h"
#include "WPILib.h"

#define DEADBAND .1

class MecanumTankDrive: public CommandBase
{
public:
	MecanumTankDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
