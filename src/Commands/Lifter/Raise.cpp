#include "Raise.h"
#include "../../RobotMap.h"

Raise::Raise()
{
	Requires(lifter);
}

void Raise::Initialize()
{
	datalogger->Log("Raise::Initialize()", STATUS_MESSAGE);
	lifter->lifterMotor->Set(-1 * MANUAL_SPEED);
}

void Raise::Execute()
{
	return;
}

bool Raise::IsFinished()
{
	return false;
}

void Raise::End()
{
	datalogger->Log("Raise::End()", ERROR_MESSAGE);
	lifter->Brake();
}

void Raise::Interrupted()
{
	datalogger->Log("Raise::Interrupted", STATUS_MESSAGE);
	lifter->Brake();
}
