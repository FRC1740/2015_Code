#include "Autonomous.h"

Autonomous::Autonomous()
{
	Requires(drivetrain);  // auto requires exclusive access to the drive train
}

void Autonomous::Initialize() // called once when the command starts
{
	SetTimeout(3);
}

void Autonomous::Execute()  // called every ~20ms while the command is running
{
	drivetrain->Go(1.0,1.0,1.0,1.0);
}

bool Autonomous::IsFinished()  // return true to end the command
{
	return IsTimedOut();
}

void Autonomous::End() // called once when the command ends
{
	drivetrain->Stop();
}

void Autonomous::Interrupted()  // called when command is interrupted (something else tries to use the same subsystem)
{
	drivetrain->Stop();
}
