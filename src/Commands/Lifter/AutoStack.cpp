#include "AutoStack.h"
#include "MoveToLevel.h"
#include "../../RobotMap.h"
#include "../Gripper/Release.h"
#include "../Gripper/Grab.h"

AutoStack::AutoStack()
{
	Requires(lifter);
	Requires(rangefinder);
	Requires(gripper);
}

void AutoStack::Initialize()
{
	printf("starting auto stack\n");
	MoveToLevel(LEVEL_TWO);
	gripper->Release();
	printf("we are here \n");
	if (rangefinder->rangefinder_top->GetRangeInches() < 8) // TODO tune this value
	{
		MoveToLevel(LEVEL_TWO);
		gripper->Grab();
		Wait(.5);
	}
	MoveToLevel(LEVEL_THREE + CLEAR_LEVEL);
}
void AutoStack::Execute()
{
	if (rangefinder->rangefinder_top->GetRangeInches() < 8) // TODO tune this value
	{
		Wait(1); // This wait is to allow the box to settle
		if (rangefinder->rangefinder_top->GetRangeInches() < 8) { // check again incase something went terribly wrong
			printf("making stack larger\n");
			MoveToLevel(LEVEL_THREE);
			Wait(.5);
			gripper->Release();
			Wait(.5);
			MoveToLevel(LEVEL_TWO);
			Wait(.5);
			gripper->Grab();
			Wait(.5);
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
