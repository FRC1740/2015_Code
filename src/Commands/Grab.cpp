#include "Grab.h"

Grab::Grab()
{
	Requires(gripper);  // grab needed exclusive access to pneumatic gripper
}

void Grab::Initialize()  // called once when the command starts
{
	gripper->Grab();
}

void Grab::Execute()  // called every ~20 ms while the command is running
{
	return;
}

bool Grab::IsFinished()  // return true when the command is completed
{
	return true;
}

void Grab::End()  // called once after IsFinished() returns true
{
	return;
}

void Grab::Interrupted()  // called once if the command is interrupted (command then terminates)
{
	return;
}
