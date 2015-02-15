#include "XBoxDrive.h"
#include "../../RobotMap.h"
#include "OI.h"

XBoxDrive::XBoxDrive()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(drivetrain);
}

// Called just before this Command runs the first time
void XBoxDrive::Initialize()
{
//	l->Log("XBoxDrive::Initialize(); XBox Drive",2);
}

// Called repeatedly when this Command is scheduled to run
void XBoxDrive::Execute(){
	drivetrain->front_left_motor->Set(oi->xboxController->GetRawAxis(1) + oi->xboxController->GetRawAxis(0) + oi->xboxController->GetRawAxis(4));
	drivetrain->front_right_motor->Set(-(oi->xboxController->GetRawAxis(1) - oi->xboxController->GetRawAxis(0) - oi->xboxController->GetRawAxis(4)));
	drivetrain->rear_left_motor->Set(-(oi->xboxController->GetRawAxis(1) + oi->xboxController->GetRawAxis(0) - oi->xboxController->GetRawAxis(4)));
	drivetrain->rear_right_motor->Set(oi->xboxController->GetRawAxis(1) - oi->xboxController->GetRawAxis(0) + oi->xboxController->GetRawAxis(4));
}

// Make this return true when this Command no longer needs to run execute()
bool XBoxDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void XBoxDrive::End()
{
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void XBoxDrive::Interrupted()
{
	drivetrain->Stop();
}
