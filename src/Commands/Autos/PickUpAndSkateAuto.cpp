#include "PickUpAndSkateAuto.h"
#include "../Lifter/CalibrateLifter.h"
#include "../Lifter/MoveToLevel.h"
#include "../Gripper/Grab.h"
#include "../../CommandBase.h"
#include "../Gripper/Release.h"
#include "../Other/DoNothing.h"
#include "SkateLeftThreeSeconds.h"

PickUpAndSkateAuto::PickUpAndSkateAuto()
{
	AddSequential(new Release());
	AddSequential(new CalibrateLifter());
	AddSequential(new DoNothing(.25));
	AddSequential(new Grab());
	AddSequential(new DoNothing(.25));
	AddSequential(new MoveToLevel(75));
	AddSequential(new DoNothing(.25));
	AddSequential(new SkateLeftThreeSeconds());
	AddSequential(new DoNothing(.25));
	AddSequential(new MoveToLevel(0));
	AddSequential(new DoNothing(.25));
	AddSequential(new Release());
}
