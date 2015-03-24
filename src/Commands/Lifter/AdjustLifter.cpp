#include "AdjustLifter.h"

AdjustLifter::AdjustLifter(int a)
{
	Requires(lifter);
	adjustment = a;
	direction = UP;
	start = lifter->lifterEncoder->Get();
}

// Called just before this Command runs the first time
void AdjustLifter::Initialize()
{
	datalogger->Log("Adjusting Lifter", STATUS_MESSAGE);
	if (adjustment < 0){
		direction = DOWN;
	}
	else if (adjustment > 0){
		direction = UP;
	}
	lifter->lifterMotor->Set(direction * MANUAL_SPEED);
}

void AdjustLifter::Execute()
{
	return;
}
bool AdjustLifter::IsFinished()
{
	if (direction == UP){
		return (lifter->lifterEncoder->Get() - start) > adjustment;
	}
	return (start - lifter->lifterEncoder->Get()) > adjustment;

}
void AdjustLifter::End()
{
	lifter->Brake();
}
void AdjustLifter::Interrupted()
{
	lifter->Brake();
}
