#ifndef Gripper_H
#define Gripper_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "Solenoid.h"
#include "../RobotMap.h"

class Gripper: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Solenoid *s0;
	Solenoid *s1;
public:
	Gripper();
	void Grab();
	void Release();
};

#endif
