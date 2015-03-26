#include "YellowToteAuto.h"
#include "../Drive/DriveCommands/DriveUntilRange.h"
#include "../Drive/DriveCommands/Move.h"
#include "../Lifter/MoveToLevel.h"
#include "../Lifter/CalibrateLifter.h"
#include "../../RobotMap.h"
#include "../Gripper/Grab.h"
#include "../Gripper/Release.h"
#include "../Other/DoNothing.h"

YellowToteAuto::YellowToteAuto()
{
	AddSequential(new CalibrateLifter());
	AddSequential(new DoNothing(1));
	AddSequential(new Grab());
	AddSequential(new DoNothing(1));

	AddSequential(new MoveToLevel(LEVEL_TWO + CLEAR_LEVEL));
	AddSequential(new DoNothing(1));
	AddSequential(new DriveUntilRange(20, .5)); // TODO tune this
	AddSequential(new DoNothing(1));
	AddSequential(new MoveToLevel(LEVEL_TWO));
	AddSequential(new DoNothing(1));
	AddSequential(new Release());
	AddSequential(new DoNothing(1));
	AddSequential(new MoveToLevel(LEVEL_ONE));
	AddSequential(new DoNothing(1));
	AddSequential(new Grab());
	AddSequential(new DoNothing(1));
	AddSequential(new MoveToLevel(LEVEL_TWO + CLEAR_LEVEL));

	AddSequential(new MoveToLevel(LEVEL_TWO + CLEAR_LEVEL));
	AddSequential(new DoNothing(1));
	AddSequential(new DriveUntilRange(20, .5)); // TODO tune this
	AddSequential(new DoNothing(1));
	AddSequential(new MoveToLevel(LEVEL_TWO));
	AddSequential(new DoNothing(1));
	AddSequential(new Release());
	AddSequential(new DoNothing(1));
	AddSequential(new MoveToLevel(LEVEL_ONE));
	AddSequential(new DoNothing(1));
	AddSequential(new Grab());
	AddSequential(new DoNothing(1));
	AddSequential(new MoveToLevel(LEVEL_TWO + CLEAR_LEVEL));

	AddSequential(new DoNothing(1));
	AddSequential(new Move(90, .5, 3));
	AddSequential(new DoNothing(1));
	AddSequential(new MoveToLevel(LEVEL_ONE));
	AddSequential(new DoNothing(1));
	AddSequential(new Release());


}
