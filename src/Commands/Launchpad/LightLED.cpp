#include "LightLED.h"

LightLED::LightLED()
{
	return;
}

void LightLED::Initialize()
{
	datalogger->Log("LightLED::Initialize()", STATUS_MESSAGE);
}

void LightLED::Execute()
{
	datalogger->Log("LightLED::Execute()", VERBOSE_MESSAGE);
	oi->launchPad->SetOutput(1, true);
}

bool LightLED::IsFinished()
{
	return false;
}

void LightLED::End()
{
	datalogger->Log("LightLED::End()", ERROR_MESSAGE);
	oi->launchPad->SetOutput(1, false);
}

void LightLED::Interrupted()
{
	datalogger->Log("LightLED::Interrupted()", STATUS_MESSAGE);
	oi->launchPad->SetOutput(1, false);
}
