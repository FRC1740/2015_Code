#ifndef AdjustLifter_H
#define AdjustLifter_H

#include "../../CommandBase.h"
#include "WPILib.h"

class AdjustLifter: public CommandBase
{
public:
	AdjustLifter(int);
	int adjustment;
	int start;
	int direction;
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
