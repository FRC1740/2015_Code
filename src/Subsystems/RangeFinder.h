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
	Relay *light;
public:
	RangeFinder();
	void InitDefaultCommand();
	Ultrasonic *rangefinder_bottom;
	Ultrasonic *rangefinder_top;
	void Light(unsigned int);
};

#endif
