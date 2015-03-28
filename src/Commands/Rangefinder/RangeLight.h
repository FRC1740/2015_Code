#ifndef RANGELIGHT_H
#define RANGELIGHT_H

#include "../../CommandBase.h"
#include "WPILib.h"

class RangeLight: public CommandBase
{
private:

public:
	RangeLight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
