#ifndef TELEOPDRIVE_H
#define TELEOPDRIVE_H

#include "../CommandBase.h"

#define StandardTankMode 0
#define MecanumTankMode 1
#define ThreeAxisMode 2

class TeleopDrive: public CommandBase {
public:
	TeleopDrive();
	int DriveMode;
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
