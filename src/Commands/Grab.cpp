#include "Grab.h"

Grab::Grab()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(gripper);
}

// Called just before this Command runs the first time
void Grab::Initialize()
{
	gripper->Grab();
}

// Called repeatedly when this Command is scheduled to run
void Grab::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool Grab::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void Grab::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Grab::Interrupted()
{

}
