#ifndef XBOXDRIVE_H
#define XBOXDRIVE_H

#include "../../../CommandBase.h"
#include "WPILib.h"

class XBoxDrive: public CommandBase
{
private:
public:
	XBoxDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
