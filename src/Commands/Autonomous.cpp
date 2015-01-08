#include "Autonomous.h"

Autonomous::Autonomous()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void Autonomous::Initialize()
{
	SetTimeout(3);
}

// Called repeatedly when this Command is scheduled to run
void Autonomous::Execute()
{
	drivetrain->StandardTankDrive(1.0,1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool Autonomous::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void Autonomous::End()
{
	drivetrain->StandardTankDrive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Autonomous::Interrupted()
{
	drivetrain->StandardTankDrive(0,0);
}
