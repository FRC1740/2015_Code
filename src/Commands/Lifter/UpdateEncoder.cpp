#include "UpdateEncoder.h"

UpdateEncoder::UpdateEncoder()
{
	Requires(lifter);
}

// Called just before this Command runs the first time
void UpdateEncoder::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void UpdateEncoder::Execute()
{
	SmartDashboard::PutNumber("Encoder", lifter->lifterEncoder->Get());
}

// Make this return true when this Command no longer needs to run execute()
bool UpdateEncoder::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void UpdateEncoder::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UpdateEncoder::Interrupted()
{

}
