#include "Toggle.h"

Toggle::Toggle()
{
	Requires(gripper);
}

void Toggle::Initialize()
{
	if (gripper->isOpen){
		gripper->Grab();
	}
	else{
		gripper->Release();
	}
}
void Toggle::Execute()
{
	return;
}
bool Toggle::IsFinished()
{
	return true;
}
void Toggle::End()
{
	return;
}
void Toggle::Interrupted()
{
	return;
}
