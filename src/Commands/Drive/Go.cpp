#include "Go.h"

Go::Go(int time, float fr, float fl, float rr, float rl)
{
	Requires(drivetrain);
	front_right = fr;
	rear_right = rr;
	front_left = fl;
	rear_left = rl;
	SetTimeout(time);
}

// Called just before this Command runs the first time
void Go::Initialize()
{
	drivetrain->Go(front_left, front_right, rear_left, rear_right);
}

// Called repeatedly when this Command is scheduled to run
void Go::Execute()
{
	return;
}

// Make this return true when this Command no longer needs to run execute()
bool Go::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void Go::End()
{
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Go::Interrupted()
{
	drivetrain->Stop();
}
