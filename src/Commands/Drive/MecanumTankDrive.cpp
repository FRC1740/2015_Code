#include "MecanumTankDrive.h"

MecanumTankDrive::MecanumTankDrive()
{
	Requires(drivetrain);
}

void MecanumTankDrive::Initialize()
{
	datalogger->Log("MecanumTankDrive::Initialize()", STATUS_MESSAGE);
}

void MecanumTankDrive::Execute()
{
	datalogger->Log("MecanumTankDrive::Initialize()", VERBOSE_MESSAGE);
	drivetrain->front_left_motor->Set(oi->tankDriveJoystickLeft->GetY() - oi->tankDriveJoystickLeft->GetX());
	drivetrain->rear_left_motor->Set(oi->tankDriveJoystickLeft->GetY() + oi->tankDriveJoystickLeft->GetX());
	drivetrain->front_right_motor->Set(oi->tankDriveJoystickRight->GetY() + oi->tankDriveJoystickRight->GetX());
	drivetrain->rear_right_motor->Set(oi->tankDriveJoystickRight->GetY() - oi->tankDriveJoystickRight->GetX());
}

bool MecanumTankDrive::IsFinished()
{
	return false;
}

void MecanumTankDrive::End()
{
	datalogger->Log("MecanumTankDrive::End()", ERROR_MESSAGE);
	drivetrain->Stop();
}

void MecanumTankDrive::Interrupted()
{
	datalogger->Log("MecanumTankDrive::Interrupted()", STATUS_MESSAGE);
	drivetrain->Stop();
}
