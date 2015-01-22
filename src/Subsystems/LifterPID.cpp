#include "LifterPID.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"

LifterPID::LifterPID() :
		PIDSubsystem("LifterPID", 1.0, 0, 0)
{
	lifterEncoder = new Encoder(6, 5); // FIXME pick actual port values
	lifterMotor = new Victor(4);
	upperLimit = new DigitalInput(0);
	lowerLimit = new DigitalInput(1);
	SmartDashboard::PutNumber("Encoder", lifterEncoder->Get()); // ktk - not sure if this auto updates
	SetSetpoint(360);
	lifterEncoder->Reset();
	Enable();
}

double LifterPID::ReturnPIDInput()
{
	SmartDashboard::PutNumber("Encoder", lifterEncoder->Get());
	return lifterEncoder->Get();
}
void LifterPID::Reset(){
	while (lowerLimit->Get() != 1){ // WARNING DO NOT USE ON ACTUAL ROBOT, normally open or closed switch?
		lifterMotor->Set(-1);
	}
	lifterMotor->Set(0);
	lifterEncoder->Reset();
	SetSetpoint(0);
}
void LifterPID::UsePIDOutput(double output)
{
	lifterMotor->Set(output / 2);
}

void LifterPID::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
}
