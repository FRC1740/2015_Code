#include "DriveUntilRange.h"

DriveUntilRange::DriveUntilRange(int inches, float s)
{
	Requires(drivetrain);
	speed = s;
	range = inches;
	direction = 1;
}

void DriveUntilRange::Initialize()
{
	if (rangefinder->rangefinder_bottom->GetRangeInches() > range)
	{
		direction = -1;
	}
	drivetrain->Go(speed * direction, speed * direction, speed * direction, speed * direction);
}
void DriveUntilRange::Execute()
{
	return;
}

bool DriveUntilRange::IsFinished()
{
	return rangefinder->rangefinder_bottom->GetRangeInches() < 5;
}
void DriveUntilRange::End()
{
	drivetrain->Stop();
}

void DriveUntilRange::Interrupted()
{
	drivetrain->Stop();
}
