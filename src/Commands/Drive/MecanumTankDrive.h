#ifndef MecanumTankDrive_H
#define MecanumTankDrive_H

#include "../../CommandBase.h"
#include "WPILib.h"

class MecanumTankDrive: public CommandBase
{
public:
	MecanumTankDrive(DataLogger *);
	DataLogger *l;
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
