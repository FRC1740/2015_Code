#ifndef LifterPID_H
#define LifterPID_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"

class LifterPID: public PIDSubsystem
{
private:
	Encoder* lifterEncoder;
	DigitalInput* upperLimit;
	DigitalInput* lowerLimit;
public:
	LifterPID();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	void UpdateSetPoint(double input);
	void Reset(void);
	Victor* lifterMotor;
};

#endif
