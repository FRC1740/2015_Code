#include "TeleopDrive.h"

TeleopDrive::TeleopDrive() {
	Requires(drivetrain); // lowercase drivetrain since that is how it is declared in CommandBase.h
}

// Called just before this Command runs the first time
void TeleopDrive::Initialize() {
	// we would need to read the drive mode from the smart dashboard
	DriveMode = StandardTankMode;
}

// Called repeatedly when this Command is scheduled to run
void TeleopDrive::Execute() {
	if (DriveMode == StandardTankMode){
		drivetrain->StandardTankDrive(oi->joystick_1->GetX(), oi->joystick_2->GetX());
	}
	else if (DriveMode == MecanumTankMode){
		drivetrain->MecanumTankDrive(oi->joystick_1->GetX(), oi->joystick_1->GetY(), oi->joystick_2->GetX(), oi->joystick_2->GetY());
	}
	else if (DriveMode == ThreeAxisMode){
		drivetrain->ThreeAxisDrive(oi->joystick_3->GetY(), oi->joystick_3->GetX(), oi->joystick_3->GetTwist());
	}
}

// Make this return true when this Command no longer needs to run execute()
bool TeleopDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TeleopDrive::End() {
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleopDrive::Interrupted() {
	drivetrain->Stop();
}
