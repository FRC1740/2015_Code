#ifndef BasicAuto_H
#define BasicAuto_H

#include "../../CommandBase.h"
#include "WPILib.h"

class BasicAuto: public CommandBase
{
public:
	BasicAuto();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
