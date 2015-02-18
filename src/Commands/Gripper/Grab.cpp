#include "Grab.h"

Grab::Grab()
{
	Requires(gripper);
}

void Grab::Initialize()
{
	datalogger->Log("Grab::Initialize()", DEBUG_MESSAGE);
	gripper->Grab();
}

void Grab::Execute()
{
	return;
}

bool Grab::IsFinished()
{
	return true;
}

void Grab::End()
{
	datalogger->Log("Grab::End()", DEBUG_MESSAGE);
}

void Grab::Interrupted()
{
	datalogger->Log("Grab::Interrupted()", ERROR_MESSAGE);
}
