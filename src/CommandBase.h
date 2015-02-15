#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <Commands/Command.h>
#include <Commands/Scheduler.h>

#include "Subsystems/DriveTrain.h"
#include "Subsystems/Gripper.h"
#include "Subsystems/Lifter.h"
#include "Subsystems/RangeFinder.h"
#include "OI.h"
#include "DataLogger.h"


/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command {
public:
	CommandBase(const char *name);
	CommandBase();
	static void init(DataLogger *);
	// Create a single static instance of all of your subsystems
	static DriveTrain *drivetrain;
	static Gripper *gripper;
	static Lifter *lifter;
	static OI *oi;
	static RangeFinder *rangefinder;
};

#endif
