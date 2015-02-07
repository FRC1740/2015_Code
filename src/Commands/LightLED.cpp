#include "LightLED.h"

LightLED::LightLED()
{
	return;
}

void LightLED::Initialize()
{
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
	oi->launchPad->SetOutput(1, false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LightLED::Interrupted()
{
	oi->launchPad->SetOutput(1, false);
}
