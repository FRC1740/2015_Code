#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveTrain: public Subsystem
{
public:
	Victor *front_right_motor;
	Victor *front_left_motor;
	Victor *rear_right_motor;
	Victor *rear_left_motor;
	DriveTrain();
	void Go(float, float, float, float);
	void Stop();
};

#endif
