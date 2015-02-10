#include "Level_1.h"

Level_1::Level_1(DataLogger *logger)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(lifterpid);
	l=logger;
}

// Called just before this Command runs the first time
void Level_1::Initialize()
{
	l->Log("Level_1::Initialize()", DEBUG_MESSAGE);
	lifterpid->UpdateSetpoint(LEVEL_ONE);
	l->Log("Level_1::Initialize(); Headed to Level 1!", DEBUG_MESSAGE);
}

// Called repeatedly when this Command is scheduled to run
void Level_1::Execute()
{
	return;
}

// Make this return true when this Command no longer needs to run execute()
bool Level_1::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Level_1::End()
{
	return;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Level_1::Interrupted()
{
	return;
}
