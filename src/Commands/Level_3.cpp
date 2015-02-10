#include "Level_3.h"

Level_3::Level_3(DataLogger *logger)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(lifterpid);
	l=logger;
}

// Called just before this Command runs the first time
void Level_3::Initialize()
{
	l->Log("Level_3::Initialize()", DEBUG_MESSAGE);
	lifterpid->UpdateSetpoint(LEVEL_THREE);
	l->Log("Level_3::Initialize(); Headed to Level 3!", DEBUG_MESSAGE);

}

// Called repeatedly when this Command is scheduled to run
void Level_3::Execute()
{
	return;
}

// Make this return true when this Command no longer needs to run execute()
bool Level_3::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Level_3::End()
{
	return;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Level_3::Interrupted()
{
	return;
}
