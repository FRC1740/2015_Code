#include "DriveUntilRange.h"

DriveUntilRange::DriveUntilRange(int inches, float s)
{
	Requires(drivetrain);
	Requires(rangefinder);
	speed = s;
	range = inches;
	direction = 1;
}

void DriveUntilRange::Initialize()
{
	if (rangefinder->rangefinder_bottom->GetRangeInches() < range)
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
	return rangefinder->rangefinder_bottom->GetRangeInches() < range;
}
void DriveUntilRange::End()
{
	drivetrain->Go(-.05 * direction, -.05 * direction, -.05 * direction, -.05 * direction);
	Wait(.1);
	drivetrain->Stop();
}

void DriveUntilRange::Interrupted()
{
	drivetrain->Stop();
}
