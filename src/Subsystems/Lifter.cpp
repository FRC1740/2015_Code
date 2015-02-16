#include "Lifter.h"
#include "../Commands/Lifter/UpdateEncoder.h"
#include "../RobotMap.h"

Lifter::Lifter() :
		Subsystem("ExampleSubsystem")
{
		lifterEncoder = new Encoder(LIFTER_ENCODER_PORT_0, LIFTER_ENCODER_PORT_1);
		lifterMotor = new CANTalon(LIFTER_MOTOR_CAN_CHANNEL);
		SmartDashboard::PutNumber("Encoder", lifterEncoder->Get()); // ktk - not sure if this auto updates
		lifterEncoder->Reset();
}

void Lifter::InitDefaultCommand()
{
	SetDefaultCommand(new UpdateEncoder());
}

void Lifter::Brake(){
	lifterMotor->Set(BRAKE_SPEED * UP);
}
