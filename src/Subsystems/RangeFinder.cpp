#include "RangeFinder.h"
#include "../RobotMap.h"
#include "../Commands/RangeFinder/PrintRange.h" // YOU MUST INCLUDE printrange to set it as the default command

#define LIGHT_BAR_RELAY_PORT 1 // Compiler blows chunks if using relay port 1

RangeFinder::RangeFinder() :
	Subsystem("RangeFinder")
{
	rangefinder = new Ultrasonic(2,1);
	rangefinder->SetAutomaticMode(true);
	light = new Relay(LIGHT_BAR_RELAY_PORT);
}

void RangeFinder::InitDefaultCommand()
{
	SetDefaultCommand(new PrintRange());
}

//float RangeFinder::GetVoltage()
//{
//	rangefinder->SetAverageBits(4);
//	return rangefinder->GetAverageVoltage();
//}

float RangeFinder::GetRangeIn()
{
	return rangefinder->GetRangeInches();
}

float RangeFinder::GetRangeFt()
{
	return rangefinder->GetRangeInches() / 12;
}

void RangeFinder::Light(unsigned int state)
{
	if (state)
	{
		light->Set(Relay::kForward);
//		l->Log("Turning Range Light ON", STATUS_MESSAGE);
	}
	else
	{
		light->Set(Relay::kOff);
//		l->Log("Turning Range Light OFF", STATUS_MESSAGE);
	}
}
