#include "Lower.h"
#include "../../RobotMap.h"

Lower::Lower()
{
	Requires(lifter);

}

// Called just before this Command runs the first time
void Lower::Initialize()
{
	datalogger->Log("Lower::Initialize(); Calling subsystem lifterpid->lifterMotor->Set(1 * MANUAL_SPEED)", DEBUG_MESSAGE);
	lifter->lifterMotor->Set(1 * MANUAL_SPEED); // WARNING could be the wrong direction
	datalogger->Log("Lower::Initialize(); Going Down!", DEBUG_MESSAGE);
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
	lifter->Brake();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Lower::Interrupted()
{
	datalogger->Log("Done lifting, stopping lifter", DEBUG_MESSAGE);
	lifter->Brake();
}
