#include "RangeFinder.h"
#include "../Commands/RangeFinder/PrintRange.h"
#include "../RobotMap.h"

#define LIGHT_BAR_RELAY_PORT 1

RangeFinder::RangeFinder():
	Subsystem("RangeFinder")
{
	rangefinder = new AnalogInput(RANGEFINDER_CHANNEL);
	light = new Relay(LIGHT_BAR_RELAY_PORT);
}

void RangeFinder::InitDefaultCommand()
{
	SetDefaultCommand(new PrintRange());
}

float RangeFinder::GetVoltage()
{
	rangefinder->SetAverageBits(4);
	return rangefinder->GetAverageVoltage();
}

float RangeFinder::GetRangeIn()
{
	return GetVoltage() * IN_FACTOR;
}

float RangeFinder::GetRangeFt()
{
	return GetVoltage() * FT_FACTOR;
}
void RangeFinder::Light(unsigned int state)
{
	if (state)
	{
		light->Set(Relay::kForward);
	}
	else
	{
		light->Set(Relay::kOff);
	}
}
