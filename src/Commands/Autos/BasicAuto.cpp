#include <Commands/Autos/BasicAuto.h>

// BASIC AUTO DRIVES FORWARD FOR 3 SECONDS

BasicAuto::BasicAuto()
{
	Requires(drivetrain);  // auto requires exclusive access to the drive train
}

void BasicAuto::Initialize() // called once when the command starts
{

	SetTimeout(3);
}

void BasicAuto::Execute()  // called every ~20ms while the command is running
{

	drivetrain->Go(1, 1,  1, 1);  // strafe
}

bool BasicAuto::IsFinished()  // return true to end the command
{
	return IsTimedOut();
}

void BasicAuto::End() // called once when the command ends
{

}

void BasicAuto::Interrupted()  // called when command is interrupted (something else tries to use the same subsystem)
{

}
