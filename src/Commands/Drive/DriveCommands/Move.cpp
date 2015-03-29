#include "Move.h"

Move::Move(int a, float s, double time)
{
	Requires(drivetrain);
	speed = s;
	angle = (a % 360) + ANGLE_CORRECTION; // simplify angle
	SetTimeout(time);

	// DIAGONALS ALWAYS MATCH WITH MECANUM, base everything on the front

}

void Move::Initialize()
{
	// there must be a nicer way to do this, but this works -ktk
	float left, right;
	if (angle <= 90){
		left = 1;
		right = (((90.0 - angle) / 90.0) * 2) - 1; // do some range shifting to make it a float between -1 and 1
	}
	else if (90 < angle and angle < 180){
		left = (((180.0 - angle) / 90.0) * 2) - 1;
		right = -1;
	}
	else if (180 <= angle and angle <= 270){
		left = -1;
		right = (((270.0 - angle) / 90.0) * -2) + 1;
	}
	else if (angle < 360){
		left = (((360.0 - angle) / 90.0) * -2) + 1;
		right = 1;
	}
	drivetrain->Go(left * speed, right * speed, right * speed, left * speed);
}

void Move::Execute()
{
	return;
}

bool Move::IsFinished()
{
	return IsTimedOut();
}

void Move::End()
{
	drivetrain->Stop();
}

void Move::Interrupted()
{
	drivetrain->Stop();
}
