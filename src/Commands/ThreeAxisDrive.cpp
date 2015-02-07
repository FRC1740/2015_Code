#include "ThreeAxisDrive.h"

ThreeAxisDrive::ThreeAxisDrive(DataLogger *logger)
{
	l=logger;
	Requires(drivetrain);
}

void ThreeAxisDrive::Initialize()
{
	l->Log("ThreeAxisDrive::Initialize()", STATUS_MESSAGE);
}

void ThreeAxisDrive::Execute()
{

	// The drivetrain->Go() method has built in handling for reversing motors on the left side...
	/* */

	float x = 0, y = 0, t = 0; // floats for the axes x, y, twist
	float fl = 0, fr = 0, rl = 0, rr = 0; // floats for the motor outputs

	if (oi->threeAxisJoystick->GetY() > .1 || oi->threeAxisJoystick->GetY() < -.1) // Deadband +/- .1
	{
		y = oi->threeAxisJoystick->GetY();
	}
	if (oi->threeAxisJoystick->GetX() > .1 || oi->threeAxisJoystick->GetX() < -.1)  // Deadband +/- .1
	{
		x = oi->threeAxisJoystick->GetX();
	}
	if (oi->threeAxisJoystick->GetTwist() > .1 || oi->threeAxisJoystick->GetTwist() < -.1)  // Deadband +/- .1
	{
		t = oi->threeAxisJoystick->GetTwist();
	}
	fl = y - t + x; // Front Left Wheel
	fr = y + t - x; // Front Right Wheel
	rl = y - t - x; // Rear Left Wheel
	rr = y + t + x; // Rear Right Wheel

#if (DEBUG_LEVEL == 4) // CRE Not sure if this is legit

	if (gfl!=fl || gfr!=fr || grl!=rl || grr!=rr) // Only log the movement if something changed
	{
		gfl=fl; gfr=fr; grl=rl; grr=rr;
		char *data = new char[128];
		sprintf(data, "We're moving: %2.1f, %2.1f, %2.1f, %2.1f; X=%2.1f, Y=%2.1f, Twist=%2.1f", fl, fr, rl, rr, x, y, t);
		l->Log(data, DEBUG_MESSAGE);
	}

#endif

	drivetrain->Go(fl,fr,rl,rr);
	/*
	// Alternatively, we can send the joystick inputs directly to the drivetrain->xxx->Set() methods
	drivetrain->front_left_motor->Set(oi->threeAxisJoystick->GetTwist() - oi->threeAxisJoystick->GetY() - oi->threeAxisJoystick->GetX());
	drivetrain->front_right_motor->Set(oi->threeAxisJoystick->GetTwist() + oi->threeAxisJoystick->GetY() + oi->threeAxisJoystick->GetX());
	drivetrain->rear_left_motor->Set(oi->threeAxisJoystick->GetTwist() - oi->threeAxisJoystick->GetY() + oi->threeAxisJoystick->GetX());
	drivetrain->rear_right_motor->Set(oi->threeAxisJoystick->GetTwist() + oi->threeAxisJoystick->GetY() - oi->threeAxisJoystick->GetX());
	*/
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
	l->Log("ThreeAxisDrive::End()", STATUS_MESSAGE);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ThreeAxisDrive::Interrupted()
{
	drivetrain->Stop();
	l->Log("ThreeAxisDrive::Interrupted()", STATUS_MESSAGE);
}
