#include "MoveToLevel.h"

// TODO stuck detection here too

MoveToLevel::MoveToLevel(int encoderLevel)
{
	Requires(lifter);
	Setpoint = encoderLevel;
	direction = UP; // i get a compiler warning if i dont give direction a default value, so lets pick UP
}

void MoveToLevel::Initialize()
{
	datalogger->Log("MoveToLevel::Initialize()", STATUS_MESSAGE);
	if (lifter->lifterEncoder->Get() > Setpoint)
	{
		direction = DOWN;
	}
	else
	{
		direction = UP;
	}
	if (direction == UP)
	{
		datalogger->Log("MoveToLevel::Initialize(); Moving UP", DEBUG_MESSAGE);
	}
	else
	{
		datalogger->Log("MoveToLevel::Initialize(); Moving DOWN", DEBUG_MESSAGE);
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
//	char speedString[24];
//	sprintf(speedString,"%d", speed);  // FIX ME, how do i do this with a float?
//	datalogger->Log("speedString", DEBUG_MESSAGE);
	lifter->lifterMotor->Set(speed * direction);
}

bool MoveToLevel::IsFinished()
{
	return abs(lifter->lifterEncoder->Get() - Setpoint) < 5;
}

void MoveToLevel::End()
{
	datalogger->Log("MoveToLevel::End()", STATUS_MESSAGE);
	lifter->Brake();
}

void MoveToLevel::Interrupted()
{
	datalogger->Log("MoveToLevel::Interrupted()", ERROR_MESSAGE);
	lifter->Brake();
}
