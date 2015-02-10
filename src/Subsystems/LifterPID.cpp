#include "LifterPID.h"
#include "../Commands/Level_1.h" // YOU MUST INCLUDE this to set it as the default command

LifterPID::LifterPID(DataLogger* logger) : PIDSubsystem("LifterPID", 1.0, 0, 0)
{
	lifterEncoder = new Encoder(LIFTER_ENCODER_PORT_0, LIFTER_ENCODER_PORT_1); // FIXME pick actual port values
//	lifterMotor = new Victor(LIFTER_MOTOR_PORT);
	lifterMotor = new CANTalon(LIFTER_MOTOR_CAN_CHANNEL);
//	upperLimit = new DigitalInput(UPPER_LIMIT_PORT);
//	lowerLimit = new DigitalInput(LOWER_LIMIT_PORT);
	SmartDashboard::PutNumber("Encoder", lifterEncoder->Get()); // ktk - not sure if this auto updates
//	SetSetpoint(360);
	lifterEncoder->Reset();
	l=logger;
//	Enable();
}

double LifterPID::ReturnPIDInput()
{
	char data[128] = "";
	double encoder=lifterEncoder->Get();

	SmartDashboard::PutNumber("Encoder", encoder);
	sprintf(data, "LifterPID::ReturnPIDInput(); Encoder: %5.1f", encoder);
	l->Log(data, DEBUG_MESSAGE);

	return encoder;
}
void LifterPID::Reset()
{
	l->Log("LifterPID::Reset(); Calibrating forklift...", 1);
	while (lifterMotor->IsFwdLimitSwitchClosed() == false) // This REQUIRES that the Appropriate (Fwd) Limit Switch is wired into the Talon at the BOTTOM
	{
		lifterMotor->Set(DOWN);
	}
	lifterEncoder->Reset();
	SetSetpoint(0);
	l->Log("LifterPID::Reset(); Done.", 1);
}
void LifterPID::UsePIDOutput(double output)
{
	lifterMotor->Set(output);
}
void LifterPID::UpdateSetpoint(double setpoint){
	SetSetpoint(setpoint);
}
void LifterPID::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new Level_1(l)); // The argument is a lower case "ell"
}

void LifterPID::BottomLimitCheck()
{
	if(lifterMotor->IsFwdLimitSwitchClosed())
	{
		lifterEncoder->Reset();
		l->Log("LifterPID::BottomLimitCheck(); Bottom Limit Switch Reached: Resetting Encoder", 2);
	}
}
