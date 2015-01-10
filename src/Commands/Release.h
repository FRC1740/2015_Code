#ifndef Release_H
#define Release_H

#include "../CommandBase.h"
#include "WPILib.h"

class Release: public CommandBase
{
public:
	Release();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
