#include "PickUpAndPushAuto.h"
#include "../Lifter/CalibrateLifter.h"
#include "../Lifter/MoveToLevel.h"
#include "../Gripper/Grab.h"
#include "../Drive/Go.h"
#include "../../CommandBase.h"
#include "../Gripper/Release.h"
#include "../Other/DoNothing.h"


PickUpAndPushAuto::PickUpAndPushAuto()
{
	AddSequential(new Release());
	AddSequential(new CalibrateLifter());
	AddSequential(new DoNothing(.25));
	AddSequential(new MoveToLevel(210));
	AddSequential(new DoNothing(.25));
	AddSequential(new Grab());
	AddSequential(new DoNothing(.25));
	AddSequential(new MoveToLevel(650));
	AddSequential(new Go(1.75, .5, -.5, -.5, .5));
	AddSequential(new DoNothing(.25));
	AddSequential(new Go(.5, -.5, 0, -.5, 0));
	AddSequential(new DoNothing(.25));
	AddSequential(new Go(4.85, -.55, -.5, -.55, -.5));


}
