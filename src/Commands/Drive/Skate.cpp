#include "Skate.h"

Skate::Skate(int direction, int time)
{
	Requires(drivetrain);
	selfdirection = direction;
	selftime = time;
}

void Skate::Initialize()
{
	SetTimeout(selftime);
	datalogger->Log("Skating!", VERBOSE_MESSAGE);
	drivetrain->Go(selfdirection * -1, selfdirection * 1, selfdirection * 1, selfdirection * -1);
}

void Skate::Execute()
{
	return;
}

bool Skate::IsFinished()
{
	return IsTimedOut();
}

void Skate::End()
{
	drivetrain->Stop();
}

void Skate::Interrupted()
{
	drivetrain->Stop();
}
