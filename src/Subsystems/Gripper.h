#ifndef GRIPPER_H
#define GRIPPER_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "Solenoid.h"
#include "../RobotMap.h"

class Gripper: public Subsystem
{
private:
	Solenoid *s0;
	Solenoid *s1;
public:
	Gripper();
	bool isOpen;
	bool Grab();
	bool Release();
};

#endif
