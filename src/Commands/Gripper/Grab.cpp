#include "Grab.h"

Grab::Grab(DataLogger *logger)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(gripper);
	l=logger;
}

// Called just before this Command runs the first time
void Grab::Initialize()
{
	l->Log("Grab::Initialize(); Calling subsystem gripper->Grab()", DEBUG_MESSAGE);
	gripper->Grab();
	l->Log("Grab::Initialize(); Grabbed a tote!", DEBUG_MESSAGE);
}

// Called repeatedly when this Command is scheduled to run
void Grab::Execute()
{
	return;
}

// Make this return true when this Command no longer needs to run execute()
bool Grab::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void Grab::End()
{
	return;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Grab::Interrupted()
{
	return;
}
