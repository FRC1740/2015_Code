#include "SkateLeftThreeSeconds.h"

SkateLeftThreeSeconds::SkateLeftThreeSeconds()
{
	Requires(drivetrain);
}

void SkateLeftThreeSeconds::Initialize()
{
	SetTimeout(2.75);
	datalogger->Log("Skating for 3 seconds", VERBOSE_MESSAGE);
	drivetrain->Go(1, -1, -1, 1);
}

void SkateLeftThreeSeconds::Execute()
{
	return;
}

bool SkateLeftThreeSeconds::IsFinished()
{
	return IsTimedOut();
}

void SkateLeftThreeSeconds::End()
{
	drivetrain->Stop();
}

void SkateLeftThreeSeconds::Interrupted()
{
	drivetrain->Stop();
}
