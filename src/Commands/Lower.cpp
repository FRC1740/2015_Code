#include "Lower.h"

Lower::Lower(DataLogger *logger)
{
	Requires(lifterpid);
	l=logger;
}

// Called just before this Command runs the first time
void Lower::Initialize()
{
	lifterpid->Disable();
	l->Log("Lower::Initialize(); Calling subsystem lifterpid->lifterMotor->Set(1)", DEBUG_MESSAGE);
	lifterpid->lifterMotor->Set(1); // WARNING could be the wrong direction
	l->Log("Lower::Initialize(); Going Down!", DEBUG_MESSAGE);
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
	lifterpid->UpdateSetpoint(lifterpid->lifterEncoder->Get());
	lifterpid->Enable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Lower::Interrupted()
{
	lifterpid->lifterMotor->Set(0);
	lifterpid->UpdateSetpoint(lifterpid->lifterEncoder->Get());
	lifterpid->Enable();
}
