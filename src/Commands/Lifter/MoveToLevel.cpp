#include "MoveToLevel.h"

MoveToLevel::MoveToLevel(int encoderLevel)
{
	Requires(lifter);
	Setpoint = encoderLevel;
	direction = UP; // i get a compiler warning if i dont give direction a default value, so lets pick UP
}

void MoveToLevel::Initialize()
{
	datalogger->Log("Starting to move to a level", STATUS_MESSAGE);
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
		datalogger->Log("We need to move upward", DEBUG_MESSAGE);
	}
	else {
		datalogger->Log("We need to move downward", DEBUG_MESSAGE);
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
