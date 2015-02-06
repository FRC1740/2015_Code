#ifndef LifterPID_H
#define LifterPID_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"
#include "../DataLogger.h"

class LifterPID: public PIDSubsystem
{
private:
	Encoder* lifterEncoder;
//	DigitalInput* upperLimit;
//	DigitalInput* lowerLimit;
public:
	LifterPID(DataLogger*);
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	void UpdateSetPoint(double input);
	void Reset(void);
	void BottomLimitCheck();
//	Victor* lifterMotor;
	CANTalon* lifterMotor;
	DataLogger *l=NULL;
};

#endif
