#ifndef Level_3_H
#define Level_3_H

#include "../CommandBase.h"
#include "WPILib.h"

class Level_3: public CommandBase
{
public:
	Level_3(DataLogger *);
	DataLogger* l;
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
