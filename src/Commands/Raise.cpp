#include "Raise.h"

Raise::Raise()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void Raise::Initialize()
{
	lifter->Raise();
}

// Called repeatedly when this Command is scheduled to run
void Raise::Execute()
{
	return;
}

// Make this return true when this Command no longer needs to run execute()
bool Raise::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Raise::End()
{
	lifter->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Raise::Interrupted()
{
	lifter->Stop();
}
