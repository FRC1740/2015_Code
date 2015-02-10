#ifndef Level_1_H
#define Level_1_H

#include "../CommandBase.h"
#include "WPILib.h"

class Level_1: public CommandBase
{
public:
	Level_1(DataLogger *);
	DataLogger* l;
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
