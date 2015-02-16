#include "Raise.h"
#include "../../RobotMap.h"

Raise::Raise()
{
	Requires(lifter);
}

// Called just before this Command runs the first time
void Raise::Initialize()
{
	datalogger->Log("Raise::Initialize(); Calling subsystem lifterpid->lifterMotor->Set(-1 * MANUAL_SPEED)", DEBUG_MESSAGE);
	lifter->lifterMotor->Set(-1 * MANUAL_SPEED); // WARNING could be the wrong direction
	datalogger->Log("Lower::Initialize(); Lowering forks!", DEBUG_MESSAGE);
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
	datalogger->Log("Raise Got Stuck, Ending", ERROR_MESSAGE);
	lifter->Brake();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Raise::Interrupted()
{
	datalogger->Log("Raise Finished, ending", STATUS_MESSAGE);
	lifter->Brake();
}
