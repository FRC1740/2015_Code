#include "Gripper.h"
#include "../RobotMap.h"

Gripper::Gripper() :
		Subsystem("Gripper")
{
	s0 = new Solenoid(CYLINDER_PORT0);
	s1 = new Solenoid(CYLINDER_PORT1);
}

void Gripper::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Gripper::Grab()
{
	s0->Set(true);
	s1->Set(false);
}

void Gripper::Release()
{
	s0->Set(false);
	s1->Set(true);
}
