#include "Lower.h"

Lower::Lower()
{
	Requires(lifterpid);
}

// Called just before this Command runs the first time
void Lower::Initialize()
{
	lifterpid->lifterMotor->Set(1); // WARNING could be the wrong direction
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
	lifterpid->lifterMotor->Set(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Lower::Interrupted()
{
	lifterpid->lifterMotor->Set(0);
}
