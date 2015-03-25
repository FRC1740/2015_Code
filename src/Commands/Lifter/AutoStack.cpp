#include "AutoStack.h"
#include "MoveToLevel.h"
#include "../../RobotMap.h"
#include "../Gripper/Release.h"
#include "../Gripper/Grab.h"

AutoStack::AutoStack()
{
	Requires(lifter);
}

void AutoStack::Initialize()
{
	MoveToLevel(LEVEL_THREE);
	Release();
	if (rangefinder->rangefinder_top->GetRangeInches() < 5) // TODO tune this value
	{
		MoveToLevel(LEVEL_TWO);
		Grab();
		Wait(.25);
	}
	MoveToLevel(LEVEL_THREE + CLEAR_LEVEL);
}
void AutoStack::Execute()
{
	if (rangefinder->rangefinder_top->GetRangeInches() < 5) // TODO tune this value
	{
		Wait(1); // This wait is to allow the box to settle
		if (rangefinder->rangefinder_top->GetRangeInches() < 5) { // check again incase something went terribly wrong
			MoveToLevel(LEVEL_THREE);
			Release();
			MoveToLevel(LEVEL_TWO);
			Grab();
			MoveToLevel(LEVEL_THREE + CLEAR_LEVEL);
		}
	}
}
bool AutoStack::IsFinished()
{
	return false;
}
void AutoStack::End()
{
	lifter->Brake();
}
void AutoStack::Interrupted()
{
	lifter->Brake();
}
