#include "XBoxDrive.h"
#include "../../../RobotMap.h"
#include "OI.h"

XBoxDrive::XBoxDrive()
{
	Requires(drivetrain);
}

void XBoxDrive::Initialize()
{
	datalogger->Log("XBoxDrive::Initialize()", STATUS_MESSAGE);
}

void XBoxDrive::Execute(){
	datalogger->Log("XBoxDrive::Execute()", VERBOSE_MESSAGE);
	drivetrain->front_left_motor->Set(oi->xboxController->GetRawAxis(1) + oi->xboxController->GetRawAxis(0) + oi->xboxController->GetRawAxis(4));
	drivetrain->front_right_motor->Set(-(oi->xboxController->GetRawAxis(1) - oi->xboxController->GetRawAxis(0) - oi->xboxController->GetRawAxis(4)));
	drivetrain->rear_left_motor->Set(-(oi->xboxController->GetRawAxis(1) + oi->xboxController->GetRawAxis(0) - oi->xboxController->GetRawAxis(4)));
	drivetrain->rear_right_motor->Set(oi->xboxController->GetRawAxis(1) - oi->xboxController->GetRawAxis(0) + oi->xboxController->GetRawAxis(4));
}

bool XBoxDrive::IsFinished()
{
	return false;
}

void XBoxDrive::End()
{
	datalogger->Log("XBoxDrive::End()", ERROR_MESSAGE);
	drivetrain->Stop();
}

void XBoxDrive::Interrupted()
{
	datalogger->Log("XBoxDrive::Interrupted()", STATUS_MESSAGE);
	drivetrain->Stop();
}
