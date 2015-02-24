#include "StandardTankDrive.h"

StandardTankDrive::StandardTankDrive()
{
	Requires(drivetrain);
}

void StandardTankDrive::Initialize()
{
	datalogger->Log("StandardTankDrive::Initialize()", STATUS_MESSAGE);
}
void StandardTankDrive::Execute()
{
	datalogger->Log("StandardTankDrive::Execute()", VERBOSE_MESSAGE);
	drivetrain->front_left_motor->Set(oi->tankDriveJoystickLeft->GetY());
	drivetrain->rear_left_motor->Set(oi->tankDriveJoystickLeft->GetY());
	drivetrain->front_right_motor->Set(oi->tankDriveJoystickRight->GetY());
	drivetrain->rear_right_motor->Set(oi->tankDriveJoystickRight->GetY());
}

bool StandardTankDrive::IsFinished()
{
	return false;
}

void StandardTankDrive::End()
{
	datalogger->Log("StandardTankDrive::End()", ERROR_MESSAGE);
	drivetrain->Stop();
}

void StandardTankDrive::Interrupted()
{
	datalogger->Log("StandardTankDrive::Interrupted()", STATUS_MESSAGE);
	drivetrain->Stop();
}
