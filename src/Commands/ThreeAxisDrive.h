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
	float gfl = 0, gfr = 0, grl = 0, grr = 0; // floats for the motor outputs
};

#endif
