#include "Lifter.h"
#include "../RobotMap.h"

Lifter::Lifter(DataLogger* logger) :
		Subsystem("ExampleSubsystem")
{
		lifterEncoder = new Encoder(LIFTER_ENCODER_PORT_0, LIFTER_ENCODER_PORT_1); // FIXME pick actual port values
		lifterMotor = new CANTalon(LIFTER_MOTOR_CAN_CHANNEL);
		SmartDashboard::PutNumber("Encoder", lifterEncoder->Get()); // ktk - not sure if this auto updates
		lifterEncoder->Reset();
}

void Lifter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}
void Lifter::Calibrate()
{
	l->Log("LifterPID::Reset(); Calibrating forklift...", 1);
	while (lifterMotor->IsFwdLimitSwitchClosed() == false) // This REQUIRES that the Appropriate (Fwd) Limit Switch is wired into the Talon at the BOTTOM
	{
		lifterMotor->Set(DOWN * MANUAL_SPEED);
	}
	lifterEncoder->Reset();
	l->Log("LifterPID::Reset(); Done.", 1);
}
void Lifter::GoToPoint(int encoderLevel)
{
	l->Log("LifterPID::Going to Point", 1);
	int direction;
	if (lifterEncoder->Get() > encoderLevel)
	{
		direction = DOWN;
	}
	else
	{
		direction = UP;
	}
	while (abs(lifterEncoder->Get() - encoderLevel) > 200){
		lifterMotor->Set(MAX_SPEED * direction);
	}
	while (abs(lifterEncoder->Get() - encoderLevel) > 100){
		lifterMotor->Set(HIGH_MIDDLE_SPEED * direction);
	}
	while (abs(lifterEncoder->Get() - encoderLevel) > 50){
		lifterMotor->Set(LOW_MIDDLE_SPEED * direction);
	}
	while (abs(lifterEncoder->Get() - encoderLevel) > 20){
		lifterMotor->Set(LOW_SPEED * direction);
	}
	while (abs(lifterEncoder->Get() - encoderLevel) > 1){
		lifterMotor->Set(MIN_SPEED * direction);
	}
	Brake();
}
void Lifter::Brake(){
	lifterMotor->Set(BRAKE_SPEED * UP);
}
