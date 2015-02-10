#ifndef LifterPID_H
#define LifterPID_H

#include <WPILib.h>
#include <Commands/PIDSubsystem.h>
#include <SmartDashboard/SmartDashboard.h>
#include <LiveWindow/LiveWindow.h>

#include "../RobotMap.h"
#include "../DataLogger.h"

#define DOWN 1 // FWD (Positive value)
#define UP -1 // REV (Negative value)

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
	static const double level1;
	static const double level2;
	static const double level3;

//	Victor* lifterMotor;
	CANTalon* lifterMotor;
	DataLogger *l=NULL;
};

#endif
