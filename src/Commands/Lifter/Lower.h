#ifndef Lower_H
#define Lower_H

#include "../../CommandBase.h"
#include "WPILib.h"

class Lower: public CommandBase
{
public:
	Lower(DataLogger *);
	DataLogger *l;
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
