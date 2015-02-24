#include "PrintRange.h"
#include "../../RobotMap.h"

PrintRange::PrintRange()
{
	Requires(rangefinder);
}

void PrintRange::Initialize()
{
	datalogger->Log("PrintRange::Initialize()", STATUS_MESSAGE);
}

void PrintRange::Execute()
{
//	printf("Voltage: %f V", rangefinder->GetVoltage());
//	printf("Range: %f in", rangefinder->GetRangeIn());
//	printf("Range: %f ft", rangefinder->GetRangeFt());
	if (rangefinder->GetRangeFt() < 1){
		rangefinder->Light(1);
	}
	else {
		rangefinder->Light(0);
	}
	SmartDashboard::PutNumber("Feet", rangefinder->GetRangeFt());
}

bool PrintRange::IsFinished()
{
	return false;
}

void PrintRange::End()
{
	return;
}

void PrintRange::Interrupted()
{
	return;
}
