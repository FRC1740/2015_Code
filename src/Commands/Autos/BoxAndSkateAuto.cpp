#include "BoxAndSkateAuto.h"
#include "../Drive/DriveCommands/Move.h"
#include "../Gripper/Grab.h"
#include "../Gripper/Release.h"
#include "../Lifter/AdjustLifter.h"
#include "../Other/DoNothing.h"
BoxAndSkateAuto::BoxAndSkateAuto()
{
	AddSequential(new Grab());
	AddSequential(new DoNothing(.5));
	AddSequential(new AdjustLifter(100));
	AddSequential(new DoNothing(.5));
	AddSequential(new Move(90, 1, 3));
}
