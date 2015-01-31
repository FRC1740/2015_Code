#include "ThreeAxisDrive.h"

ThreeAxisDrive::ThreeAxisDrive()
{
	Requires(drivetrain);
}

void ThreeAxisDrive::Initialize()
{

}

void ThreeAxisDrive::Execute()
{

	// The drivetrain->Go() method has built in handling for reversing motors on the left side...
	/* */
	float fl = oi->joystick_3->GetY() - oi->joystick_3->GetTwist() + oi->joystick_3->GetX(); // Front Left Wheel
	float fr = oi->joystick_3->GetY() + oi->joystick_3->GetTwist() - oi->joystick_3->GetX(); // Front Right Wheel
	float rl = oi->joystick_3->GetY() - oi->joystick_3->GetTwist() - oi->joystick_3->GetX(); // Rear Left Wheel
	float rr = oi->joystick_3->GetY() + oi->joystick_3->GetTwist() + oi->joystick_3->GetX(); // Rear Right Wheel

	drivetrain->Go(fl,fr,rl,rr);

	/*
	// Alternatively, we can send the joystick inputs directly to the drivetrain->xxx->Set() methods
	drivetrain->front_left_motor->Set(oi->joystick_3->GetTwist() - oi->joystick_3->GetY() - oi->joystick_3->GetX());
	drivetrain->front_right_motor->Set(oi->joystick_3->GetTwist() + oi->joystick_3->GetY() + oi->joystick_3->GetX());
	drivetrain->rear_left_motor->Set(oi->joystick_3->GetTwist() - oi->joystick_3->GetY() + oi->joystick_3->GetX());
	drivetrain->rear_right_motor->Set(oi->joystick_3->GetTwist() + oi->joystick_3->GetY() - oi->joystick_3->GetX());
	/* */
}

// Make this return true when this Command no longer needs to run execute()
bool ThreeAxisDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ThreeAxisDrive::End()
{
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ThreeAxisDrive::Interrupted()
{
	drivetrain->Stop();
}
