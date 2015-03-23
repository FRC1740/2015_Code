#include "TrashCan.h"
#include "../Lifter/CalibrateLifter.h"
#include "../Lifter/MoveToLevel.h"
#include "../Gripper/Grab.h"
#include "../Drive/DriveCommands/Move.h"
#include "../../CommandBase.h"
#include "../Gripper/Release.h"
#include "../Other/DoNothing.h"

TrashCan::TrashCan()
{
	AddSequential(new Release());
	AddSequential(new CalibrateLifter());
	AddSequential(new DoNothing(.25));
	AddSequential(new MoveToLevel(210));
	AddSequential(new DoNothing(.25));
	AddSequential(new Grab());
	AddSequential(new DoNothing(.25));
	AddSequential(new MoveToLevel(650));
	AddSequential(new DoNothing(.25));
	AddSequential(new Move(180, .5, 5));
}
