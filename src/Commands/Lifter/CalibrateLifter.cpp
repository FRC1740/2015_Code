#include "CalibrateLifter.h"

CalibrateLifter::CalibrateLifter()
{
	Requires(lifter);
}

void CalibrateLifter::Initialize()
{
	datalogger->Log("Starting to calibrate lifter", STATUS_MESSAGE);
	while (lifter->lifterMotor->IsFwdLimitSwitchClosed() == false) // This REQUIRES that the Appropriate (Fwd) Limit Switch is wired into the Talon at the BOTTOM
	{
		lifter->lifterMotor->Set(DOWN * MANUAL_SPEED);
	}
	lifter->lifterEncoder->Reset();
}

void CalibrateLifter::Execute()
{
	return;
}

bool CalibrateLifter::IsFinished()
{
	return true;
}

void CalibrateLifter::End()
{
	datalogger->Log("Calibration Completed", STATUS_MESSAGE);
	lifter->Brake();
}

void CalibrateLifter::Interrupted()
{
	datalogger->Log("Calibration Failed", ERROR_MESSAGE);
	lifter->Brake();
}