#ifndef Level_2_H
#define Level_2_H

#include "../CommandBase.h"
#include "WPILib.h"

class Level_2: public CommandBase
{
public:
	Level_2(DataLogger *);
	DataLogger* l;
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
