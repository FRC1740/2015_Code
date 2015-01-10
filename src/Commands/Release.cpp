#include "Release.h"

Release::Release()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Gripper);
}

// Called just before this Command runs the first time
void Release::Initialize()
{
	Gripper->Release();

}

// Called repeatedly when this Command is scheduled to run
void Release::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool Release::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void Release::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Release::Interrupted()
{

}
