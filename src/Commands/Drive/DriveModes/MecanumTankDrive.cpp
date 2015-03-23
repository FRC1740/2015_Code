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
	float right_x = 0;
	float right_y = 0;
	float left_x = 0;
	float left_y = 0;
	if (oi->tankDriveJoystickLeft->GetX() > DEADBAND || oi->tankDriveJoystickLeft->GetX() < -DEADBAND){
		left_x = oi->tankDriveJoystickLeft->GetX();
	}
	if (oi->tankDriveJoystickLeft->GetY() > DEADBAND || oi->tankDriveJoystickLeft->GetY() < -DEADBAND){
		left_y = oi->tankDriveJoystickLeft->GetY();
	}
	if (oi->tankDriveJoystickRight->GetX() > DEADBAND || oi->tankDriveJoystickRight->GetX() < -DEADBAND){
		right_x = oi->tankDriveJoystickRight->GetX();
	}
	if (oi->tankDriveJoystickRight->GetY() > DEADBAND || oi->tankDriveJoystickRight->GetY() < -DEADBAND){
		right_y = oi->tankDriveJoystickRight->GetY();
	}
	datalogger->Log("MecanumTankDrive::Initialize()", VERBOSE_MESSAGE);
	drivetrain->front_left_motor->Set(left_y - left_x);
	drivetrain->rear_left_motor->Set(left_y + left_x);
	drivetrain->front_right_motor->Set(right_y + right_x);
	drivetrain->rear_right_motor->Set(right_y - right_x);
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
