#include "Gripper.h"

Gripper::Gripper() : Subsystem("Gripper")
{
	s0 = new Solenoid(CYLINDER_PORT0);
	s1 = new Solenoid(CYLINDER_PORT1);
	isOpen = true;
}

void Gripper::Grab()
{
	s0->Set(true);
	s1->Set(false);
	isOpen = false;
}

void Gripper::Release()
{
	isOpen = true;
	s0->Set(false);
	s1->Set(true);
}
