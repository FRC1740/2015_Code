#ifndef UPDATEENCODER_H
#define UPDATEENCODER_H

#include "../../CommandBase.h"
#include "WPILib.h"

class UpdateEncoder: public CommandBase
{
public:
	UpdateEncoder();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
