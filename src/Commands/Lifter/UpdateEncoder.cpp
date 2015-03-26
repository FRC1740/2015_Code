#include "UpdateEncoder.h"

UpdateEncoder::UpdateEncoder()
{
	//Requires(lifter);
}

void UpdateEncoder::Initialize()
{
	return;
}

void UpdateEncoder::Execute()
{
	SmartDashboard::PutNumber("Encoder", lifter->lifterEncoder->Get());
}

bool UpdateEncoder::IsFinished()
{
	return false;
}

void UpdateEncoder::End()
{
	return;
}

void UpdateEncoder::Interrupted()
{
	return;
}
