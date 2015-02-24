#include "CommandBase.h"

CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}

DriveTrain* CommandBase::drivetrain = NULL;
Gripper* CommandBase::gripper = NULL;
Lifter* CommandBase::lifter = NULL;
RangeFinder* CommandBase::rangefinder = NULL;
OI* CommandBase::oi = NULL;
DataLogger* CommandBase::datalogger = NULL;

void CommandBase::init() {
	drivetrain = new DriveTrain();
	datalogger = new DataLogger();
	gripper = new Gripper();
	lifter = new Lifter();
	rangefinder = new RangeFinder();
	oi = new OI();

	SmartDashboard::PutData(drivetrain);
	SmartDashboard::PutData(lifter);
}
