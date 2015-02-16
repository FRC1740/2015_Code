#include "SkateLeftThreeSeconds.h"

SkateLeftThreeSeconds::SkateLeftThreeSeconds()
{
	Requires(drivetrain);
}

// Called just before this Command runs the first time
void SkateLeftThreeSeconds::Initialize()
{
	SetTimeout(2.75);
	datalogger->Log("Skating for 3 seconds", VERBOSE_MESSAGE);
	drivetrain->Go(-1, +1, 1, -1);
}

// Called repeatedly when this Command is scheduled to run
void SkateLeftThreeSeconds::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SkateLeftThreeSeconds::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void SkateLeftThreeSeconds::End()
{
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SkateLeftThreeSeconds::Interrupted()
{
	drivetrain->Stop();
}
