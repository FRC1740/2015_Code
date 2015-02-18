#include "Gripper.h"

Gripper::Gripper() : Subsystem("Gripper")
{
	s0 = new Solenoid(CYLINDER_PORT0);
	s1 = new Solenoid(CYLINDER_PORT1);
}

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
