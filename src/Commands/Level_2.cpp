#include "Level_2.h"

Level_2::Level_2(DataLogger *logger)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(lifterpid);
	l=logger;
}

// Called just before this Command runs the first time
void Level_2::Initialize()
{
	l->Log("Level_2::Initialize();", DEBUG_MESSAGE);
	lifterpid->UpdateSetpoint(LEVEL_TWO);
	l->Log("Level_2::Initialize(); Headed to Level 2!", DEBUG_MESSAGE);
}

// Called repeatedly when this Command is scheduled to run
void Level_2::Execute()
{
	return;
}

// Make this return true when this Command no longer needs to run execute()
bool Level_2::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Level_2::End()
{
	return;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Level_2::Interrupted()
{
	return;
}
