#ifndef ThreeAxisDrive_H
#define ThreeAxisDrive_H

#include "math.h"
#include "../CommandBase.h"
#include "WPILib.h"
#include "DataLogger.h"

class ThreeAxisDrive: public CommandBase
{
public:
	ThreeAxisDrive(DataLogger*);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	DataLogger *l=NULL;
};

#endif
