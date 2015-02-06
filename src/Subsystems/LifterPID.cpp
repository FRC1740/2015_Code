#include "LifterPID.h"

LifterPID::LifterPID(DataLogger* logger) : PIDSubsystem("LifterPID", 1.0, 0, 0)
{
	lifterEncoder = new Encoder(LIFTER_ENCODER_PORT_0, LIFTER_ENCODER_PORT_1); // FIXME pick actual port values
//	lifterMotor = new Victor(LIFTER_MOTOR_PORT);
	lifterMotor = new CANTalon(LIFTER_MOTOR_CAN_CHANNEL);
//	upperLimit = new DigitalInput(UPPER_LIMIT_PORT);
//	lowerLimit = new DigitalInput(LOWER_LIMIT_PORT);
	SmartDashboard::PutNumber("Encoder", lifterEncoder->Get()); // ktk - not sure if this auto updates
	SetSetpoint(360);
	lifterEncoder->Reset();
	l=logger;
//	Enable();
}

double LifterPID::ReturnPIDInput()
{
	SmartDashboard::PutNumber("Encoder", lifterEncoder->Get());
	return lifterEncoder->Get();
}
void LifterPID::Reset()
{
//	while (lifterMotor->IsRevLimitSwitchClosed() == false) // This REQUIRES that the Appropriate (Reverse?) Limit Switch is wired into the Talon
	{
		lifterMotor->Set(-1);
		Wait(.25);
		lifterMotor->Set(1);
		Wait(.25);
	}
	lifterEncoder->Reset();
	SetSetpoint(0);
	l->Log("LifterPID::Reset(); Done.", 1);
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

void LifterPID::BottomLimitCheck()
{
	if(lifterMotor->IsRevLimitSwitchClosed())
	{
		lifterEncoder->Reset();
		l->Log("LifterPID::BottomLimitCheck(); Bottom Limit Switch Reached: Resetting Encoder", 2);
	}
}
