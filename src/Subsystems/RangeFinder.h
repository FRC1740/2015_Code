#ifndef RangeFinder_H
#define RangeFinder_H

#include <WPILib.h>
#include "Commands/Subsystem.h"
#include "DataLogger.h"

#define IN_FACTOR 1 / .0098
#define FT_FACTOR IN_FACTOR / 12

class RangeFinder: public Subsystem
{
private:
	AnalogInput *rangefinder;
	Relay *light;
public:
	RangeFinder(DataLogger *);
	DataLogger *l;
	void InitDefaultCommand();
	float GetVoltage();
	float GetRangeIn();
	float GetRangeFt();
	void Light(unsigned int);
};

#endif
