#include "Lower.h"
#include "../../RobotMap.h"

Lower::Lower()
{
	Requires(lifter);
}

void Lower::Initialize()
{
	datalogger->Log("Lower::Initialize()", STATUS_MESSAGE);
	lifter->lifterMotor->Set(1 * MANUAL_SPEED);
}

void Lower::Execute()
{
	return;
}

bool Lower::IsFinished()
{
	return false;
}

void Lower::End()
{
	lifter->Brake();
	datalogger->Log("Lower::End(); Lower Got Stuck", ERROR_MESSAGE);
}

void Lower::Interrupted()
{
	datalogger->Log("Lower::Interrupted()", STATUS_MESSAGE);
	lifter->Brake();
}
