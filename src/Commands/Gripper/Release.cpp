#include "Release.h"

Release::Release()
{
    Requires(gripper);
}

void Release::Initialize()
{
	datalogger->Log("Release::Initialize()", DEBUG_MESSAGE);
	gripper->Release();
}

void Release::Execute()
{
	return;
}

bool Release::IsFinished()
{
	return true;
}

void Release::End()
{
	datalogger->Log("Release::End()", DEBUG_MESSAGE);
}

void Release::Interrupted()
{
	datalogger->Log("Release::Interrupted()", ERROR_MESSAGE);
}
