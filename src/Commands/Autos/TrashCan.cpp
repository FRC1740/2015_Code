#include "TrashCan.h"
#include "../Lifter/AdjustLifter.h"
#include "../Gripper/Grab.h"
#include "../Drive/DriveCommands/Move.h"
#include "../../CommandBase.h"
#include "../Gripper/Release.h"
#include "../Other/DoNothing.h"

TrashCan::TrashCan()
{
	AddSequential(new Release());
	AddSequential(new DoNothing(.5));
	AddSequential(new Grab());
	AddSequential(new DoNothing(.5));
	AddSequential(new AdjustLifter(100));
	AddSequential(new DoNothing(.5));
	AddSequential(new Move(180, .5, 3.9));
}
