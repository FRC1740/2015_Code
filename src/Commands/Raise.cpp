#include "Raise.h"

Raise::Raise()
{
	Requires(lifterpid);
}

// Called just before this Command runs the first time
void Raise::Initialize()
{
	lifterpid->lifterMotor->Set(-1); // WARNING
}

// Called repeatedly when this Command is scheduled to run
void Raise::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool Raise::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Raise::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Raise::Interrupted()
{

}
