#include <Commands/SetTilt.h>

SetTilt::SetTilt()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(lifter);
}

// Called just before this Command runs the first time
void SetTilt::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void SetTilt::Execute()
{
		lifter->Tilt(oi->joystick_3->GetThrottle());
}

// Make this return true when this Command no longer needs to run execute()
bool SetTilt::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void SetTilt::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetTilt::Interrupted()
{

}
