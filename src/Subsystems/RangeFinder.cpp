#include "RangeFinder.h"
#include "../RobotMap.h"

RangeFinder::RangeFinder() :
	Subsystem("ExampleSubsystem")
{
	rangefinder = new AnalogInput(RANGEFINDER_CHANNEL);
}

void RangeFinder::InitDefaultCommand()
{
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
