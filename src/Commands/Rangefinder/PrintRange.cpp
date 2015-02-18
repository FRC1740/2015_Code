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
