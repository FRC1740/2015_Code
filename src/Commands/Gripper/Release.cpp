#include "Release.h"

Release::Release()
{
    Requires(gripper);
}

void Release::Initialize()
{
	datalogger->Log("Release::Initialize(); Calling gripper->Release() subsystem", DEBUG_MESSAGE);
	gripper->Release();
	datalogger->Log("Release::Initialize(); Dropped a tote!", DEBUG_MESSAGE);
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
	datalogger->Log("Release is ending", DEBUG_MESSAGE);
	return;
}

void Release::Interrupted()
{
	datalogger->Log("Release was interrupted", ERROR_MESSAGE);
	return;
}
