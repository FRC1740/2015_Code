#include "Raise.h"

Raise::Raise(DataLogger *logger)
{
	Requires(lifterpid);
	l=logger;
}

// Called just before this Command runs the first time
void Raise::Initialize()
{
	l->Log("Raise::Initialize(); Calling subsystem lifterpid->lifterMotor->Set(-1)", DEBUG_MESSAGE);
	lifterpid->lifterMotor->Set(-1); // WARNING could be the wrong direction
	l->Log("Lower::Initialize(); Lowering forks!", DEBUG_MESSAGE);
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
	lifterpid->lifterMotor->Set(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Raise::Interrupted()
{
	lifterpid->lifterMotor->Set(0);
}
