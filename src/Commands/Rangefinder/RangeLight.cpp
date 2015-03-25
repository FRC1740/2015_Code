#include "RangeLight.h"
#include "../../RobotMap.h"

RangeLight::RangeLight()
{
	Requires(rangefinder);
}

void RangeLight::Initialize()
{
	datalogger->Log("RangeLight::Initialize()", STATUS_MESSAGE);
}

void RangeLight::Execute()
{

	if (rangefinder->rangefinder_bottom->GetRangeInches() < 8.5){
		rangefinder->Light(1);
	}
	else {
		rangefinder->Light(0);
	}
	SmartDashboard::PutNumber("Top Range:", rangefinder->rangefinder_top->GetRangeInches());
	SmartDashboard::PutNumber("Bottom Range:", rangefinder->rangefinder_bottom->GetRangeInches());
}

bool RangeLight::IsFinished()
{
	return false;
}

void RangeLight::End()
{
	return;
}

void RangeLight::Interrupted()
{
	return;
}
