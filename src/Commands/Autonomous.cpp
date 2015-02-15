#include "Autonomous.h"

Autonomous::Autonomous()
{
	Requires(drivetrain);  // auto requires exclusive access to the drive train
}

void Autonomous::Initialize() // called once when the command starts
{

}

void Autonomous::Execute()  // called every ~20ms while the command is running
{
	drivetrain->Go(1, -1,  1, -1);  // strafe
}

bool Autonomous::IsFinished()  // return true to end the command
{
	return IsTimedOut();
}

void Autonomous::End() // called once when the command ends
{

}

void Autonomous::Interrupted()  // called when command is interrupted (something else tries to use the same subsystem)
{

}
