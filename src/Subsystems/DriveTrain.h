#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveTrain: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Victor *front_right_motor;
	Victor *front_left_motor;
	Victor *rear_right_motor;
	Victor *rear_left_motor;
public:
	DriveTrain();
	void InitDefaultCommand();
	void StandardTankDrive(float, float);
	void MecanumTankDrive(float, float, float, float);
	void ThreeAxisDrive(float, float, float);
	void Stop();
};

#endif
