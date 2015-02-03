#include "RangeFinder.h"
#include "../RobotMap.h"
#include "../Commands/PrintRange.h" // YOU MUST INCLUDE printrange to set it as the default command

RangeFinder::RangeFinder() :
	Subsystem("RangeFinder")
{
	rangefinder = new AnalogInput(RANGEFINDER_CHANNEL);
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
