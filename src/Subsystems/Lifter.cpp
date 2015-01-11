#include "Lifter.h"
#include "../RobotMap.h"

Lifter::Lifter() :
		Subsystem("Lifter")
{
	liftMotor = new CANTalon(0);
	tiltMotor = new CANTalon(1);
}

void Lifter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Lifter::Raise()
{
	liftMotor->Set(1);
}

void Lifter::Lower()
{
	liftMotor->Set(-1);

}
void Lifter::Stop()
{
	liftMotor->Set(0);
}
void Lifter::TiltForward()
{
	tiltMotor->Set(.5);
}
void Lifter::TiltBack()
{
	tiltMotor->Set(-.5);
}
void Lifter::TiltStop()
{
	tiltMotor->Set(0);
}
void Lifter::StopAll()
{
	Lifter::Stop();
	Lifter::TiltStop();
}

