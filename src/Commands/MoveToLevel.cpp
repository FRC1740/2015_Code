#include "MoveToLevel.h"

MoveToLevel::MoveToLevel(int encoderLevel)
{
	Requires(lifter);
	Setpoint = encoderLevel;
	direction = UP; // i get a compiler warning if i dont give direction a default value, so lets pick UP
}

void MoveToLevel::Initialize()
{
	if (lifter->lifterEncoder->Get() > Setpoint)
	{
		direction = DOWN;
	}
	else
	{
		direction = UP;
	}
}

void MoveToLevel::Execute()
{
	float speed = sqrt(abs(lifter->lifterEncoder->Get() - Setpoint)) / sqrt(MAX_ENCODER_VALUE);  // sqrt to take longer to reach min speed
	if (speed < MIN_SPEED){
		speed = MIN_SPEED;
	}
	else if (speed > MAX_SPEED){
		speed = MAX_SPEED;
	}
	lifter->lifterMotor->Set(speed);
}

bool MoveToLevel::IsFinished()
{
	return abs(lifter->lifterEncoder->Get() - Setpoint) > 5;
}

void MoveToLevel::End()
{
	lifter->Brake();
}


void MoveToLevel::Interrupted()
{
	lifter->Brake();
}
