#include "PrintRange.h"
#include "../../RobotMap.h"

PrintRange::PrintRange()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(rangefinder);
}

// Called just before this Command runs the first time
void PrintRange::Initialize()
{
	printf("Starting Rangefinder");
}

// Called repeatedly when this Command is scheduled to run
void PrintRange::Execute()
{
	printf("Voltage: %f V", rangefinder->GetVoltage());
	printf("Range: %f in", rangefinder->GetRangeIn());
	printf("Range: %f ft", rangefinder->GetRangeFt());
	SmartDashboard::PutNumber("Feet", rangefinder->GetRangeFt());
}

// Make this return true when this Command no longer needs to run execute()
bool PrintRange::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void PrintRange::End()
{
	printf("Stopping Rangefinder");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PrintRange::Interrupted()
{
	printf("Rangefinder Interrupted");
}
