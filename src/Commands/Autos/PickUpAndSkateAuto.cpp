#include "PickUpAndSkateAuto.h"
#include "../Lifter/CalibrateLifter.h"
#include "../Lifter/MoveToLevel.h"
#include "../Gripper/Grab.h"
#include "../../CommandBase.h"
#include "../Gripper/Release.h"
#include "SkateLeftThreeSeconds.h"

PickUpAndSkateAuto::PickUpAndSkateAuto()
{
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
	AddSequential(new CalibrateLifter());
	AddSequential(new Grab());
	AddSequential(new MoveToLevel(50));
	AddSequential(new SkateLeftThreeSeconds());
	AddSequential(new MoveToLevel(0));
	AddSequential(new Release());
//	AddSequential(new DoNothingAuto());
//	datalogger->Log("We should never get there", ERROR_MESSAGE);
}
