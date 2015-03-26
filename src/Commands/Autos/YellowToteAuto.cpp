#include "YellowToteAuto.h"
#include "../Drive/DriveCommands/DriveUntilRange.h"
#include "../Drive/DriveCommands/Move.h"
#include "../Lifter/MoveToLevel.h"
#include "../../RobotMap.h"
#include "../Gripper/Grab.h"
#include "../Gripper/Release.h"
#include "../Other/DoNothing.h"

YellowToteAuto::YellowToteAuto()
{
	AddSequential(new Release());
	AddSequential(new MoveToLevel(LEVEL_ONE));
	AddSequential(new DoNothing(.5));
	AddSequential(new DriveUntilRange(6, .5)); // TODO tune this
	AddSequential(new Grab());
	AddSequential(new MoveToLevel(LEVEL_TWO + CLEAR_LEVEL));

	AddSequential(new DriveUntilRange(6, .5)); // TODO tune this
	AddSequential(new MoveToLevel(LEVEL_TWO));
	AddSequential(new DoNothing(.5));
	AddSequential(new Release());
	AddSequential(new DoNothing(.5));
	AddSequential(new MoveToLevel(LEVEL_ONE));
	AddSequential(new DoNothing(.5));
	AddSequential(new Grab());
	AddSequential(new DoNothing(.5));
	AddSequential(new MoveToLevel(LEVEL_TWO + CLEAR_LEVEL));

	AddSequential(new DriveUntilRange(6, .5)); // TODO tune this
	AddSequential(new MoveToLevel(LEVEL_TWO));
	AddSequential(new DoNothing(.5));
	AddSequential(new Release());
	AddSequential(new DoNothing(.5));
	AddSequential(new MoveToLevel(LEVEL_ONE));
	AddSequential(new DoNothing(.5));
	AddSequential(new Grab());
	AddSequential(new DoNothing(.5));
	AddSequential(new MoveToLevel(LEVEL_TWO + CLEAR_LEVEL));

	AddSequential(new Move(90, .5, 3));
	AddSequential(new MoveToLevel(LEVEL_ONE));
	AddSequential(new Release());


}
