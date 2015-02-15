#include "Release.h"

Release::Release()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
    Requires(gripper);
}

// Called just before this Command runs the first time
void Release::Initialize()
{
//	l->Log("Release::Initialize(); Calling gripper->Release() subsystem", DEBUG_MESSAGE);
	gripper->Release();
//	l->Log("Release::Initialize(); Dropped a tote!", DEBUG_MESSAGE);
}

// Called repeatedly when this Command is scheduled to run
void Release::Execute()
{
	return;
}

// Make this return true when this Command no longer needs to run execute()
bool Release::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void Release::End()
{
	return;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Release::Interrupted()
{
	return;
}
