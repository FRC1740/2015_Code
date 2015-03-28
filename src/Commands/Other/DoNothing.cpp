#include <Commands/Other/DoNothing.h>

DoNothing::DoNothing(double input)
{
	timer = input;
}
void DoNothing::Initialize()
{
	SetTimeout(timer);
}
void DoNothing::Execute()
{
	return;
}
bool DoNothing::IsFinished()
{
	return IsTimedOut();
}
void DoNothing::End()
{
	return;
}
void DoNothing::Interrupted()
{
	return;
}
