#include "Lower.h"

Lower::Lower()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void Lower::Initialize()
{
	lifter->Lower();
}

// Called repeatedly when this Command is scheduled to run
void Lower::Execute()
{
	return;
}

// Make this return true when this Command no longer needs to run execute()
bool Lower::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Lower::End()
{
	lifter->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Lower::Interrupted()
{
	lifter->Stop();
}
