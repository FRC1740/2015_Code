#include <Commands/Autos/BasicAuto.h>

// BASIC AUTO DRIVES FORWARD FOR 3 SECONDS

BasicAuto::BasicAuto()
{
	Requires(drivetrain);
}

void BasicAuto::Initialize()
{
	datalogger->Log("starting basic auto", STATUS_MESSAGE);
	SetTimeout(5);
}

void BasicAuto::Execute()
{
	datalogger->Log("Basic Auto Driving", VERBOSE_MESSAGE);
	drivetrain->Go(.5, .5, .5, .5);
}

bool BasicAuto::IsFinished()
{
	return IsTimedOut();
}

void BasicAuto::End()
{
	datalogger->Log("Basic Auto timed out, stopping", STATUS_MESSAGE);
	drivetrain->Stop();
}

void BasicAuto::Interrupted()
{
	datalogger->Log("Basic Auto interrupted, stopping", STATUS_MESSAGE);
	drivetrain->Stop();
}
