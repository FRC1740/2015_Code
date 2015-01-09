#ifndef ThreeAxisDrive_H
#define ThreeAxisDrive_H

#include "../CommandBase.h"
#include "WPILib.h"

class ThreeAxisDrive: public CommandBase
{
public:
	ThreeAxisDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
