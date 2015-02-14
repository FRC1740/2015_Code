#include "Autonomous.h"

Autonomous::Autonomous()
{
	Requires(drivetrain);  // auto requires exclusive access to the drive train
}

void Autonomous::Initialize() // called once when the command starts
{

	lifterpid->Reset();
	while (lifterpid->lifterMotor->IsFwdLimitSwitchClosed() == false){

	}
	gripper->Grab();
	lifterpid->UpdateSetpoint(50);
	SetTimeout(3);
}

void Autonomous::Execute()  // called every ~20ms while the command is running
{
	drivetrain->Go(1, -1,  1, -1);
}

bool Autonomous::IsFinished()  // return true to end the command
{
	return IsTimedOut();
}

void Autonomous::End() // called once when the command ends
{
	drivetrain->Stop();
	lifterpid->UpdateSetpoint(0);
	Wait(1);
	gripper->Release();

}

void Autonomous::Interrupted()  // called when command is interrupted (something else tries to use the same subsystem)
{
	gripper->Release(); // not sure if this is a great idea
	drivetrain->Stop();
}
