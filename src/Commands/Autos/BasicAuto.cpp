#include <Commands/Autos/BasicAuto.h>

// BASIC AUTO DRIVES FORWARD FOR 3 SECONDS

BasicAuto::BasicAuto()
{
	Requires(drivetrain);  // auto requires exclusive access to the drive train
}

void BasicAuto::Initialize() // called once when the command starts
{
	datalogger->Log("starting basic auto", STATUS_MESSAGE);
	SetTimeout(3);
}

void BasicAuto::Execute()  // called every ~20ms while the command is running
{
	datalogger->Log("Basic Auto Driving", VERBOSE_MESSAGE);
	drivetrain->Go(1, 1,  1, 1);
}

bool BasicAuto::IsFinished()  // return true to end the command
{
	return IsTimedOut();
}

void BasicAuto::End() // called once when the command ends
{
	datalogger->Log("Basic Auto timed out, stopping", STATUS_MESSAGE);
	drivetrain->Stop();
}

void BasicAuto::Interrupted()  // called when command is interrupted (something else tries to use the same subsystem)
{
	datalogger->Log("Basic Auto interrupted, stopping", STATUS_MESSAGE);
	drivetrain->Stop();
}
