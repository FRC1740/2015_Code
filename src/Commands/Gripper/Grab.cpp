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
	datalogger->Log("Grab::Initialize(); Calling subsystem gripper->Grab()", DEBUG_MESSAGE);
	gripper->Grab();
	datalogger->Log("Grab::Initialize(); Grabbed a tote!", DEBUG_MESSAGE);
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
	datalogger->Log("Grab::End()", DEBUG_MESSAGE);
	return;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Grab::Interrupted()
{
	datalogger->Log("Grab was interrupted", ERROR_MESSAGE);
	return;
}
