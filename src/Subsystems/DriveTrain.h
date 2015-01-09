#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveTrain: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	// however the motors are public since its clearer to directly control the motors instead of having individual set functions
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
