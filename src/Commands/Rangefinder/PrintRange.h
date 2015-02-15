#ifndef PrintRange_H
#define PrintRange_H

#include "../../CommandBase.h"
#include "WPILib.h"

class PrintRange: public CommandBase
{
private:

public:
	PrintRange();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
