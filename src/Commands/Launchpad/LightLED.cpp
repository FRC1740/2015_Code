#include "LightLED.h"

LightLED::LightLED()
{
	return;
}

void LightLED::Initialize()
{
	datalogger->Log("Lighting a LED", STATUS_MESSAGE);
	return;
}

void LightLED::Execute()
{
	oi->launchPad->SetOutput(1, true);
}

// Make this return true when this Command no longer needs to run execute()
bool LightLED::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void LightLED::End()
{
	datalogger->Log("Ending, turning off LED", STATUS_MESSAGE);
	oi->launchPad->SetOutput(1, false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LightLED::Interrupted()
{
	datalogger->Log("Interrupted, turning off LED", STATUS_MESSAGE);
	oi->launchPad->SetOutput(1, false);
}
