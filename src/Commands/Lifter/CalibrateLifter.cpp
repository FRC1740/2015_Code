#include "CalibrateLifter.h"

CalibrateLifter::CalibrateLifter()
{
	Requires(lifter);
}

void CalibrateLifter::Initialize()
{
	datalogger->Log("Starting to calibrate lifter", STATUS_MESSAGE);
	lifter->lifterMotor->Set(DOWN * MANUAL_SPEED);
}

void CalibrateLifter::Execute()
{
	return;
}

bool CalibrateLifter::IsFinished()
{
	return lifter->lifterMotor->IsFwdLimitSwitchClosed();
}

void CalibrateLifter::End()
{
	lifter->Brake();
	lifter->lifterEncoder->Reset();
	datalogger->Log("CalibrateLifter::End(); Calibration Completed", STATUS_MESSAGE);
}

void CalibrateLifter::Interrupted()
{
	datalogger->Log("CalibrateLifter::Interrupted(); Calibration Failed", ERROR_MESSAGE);
	lifter->Brake();
}
