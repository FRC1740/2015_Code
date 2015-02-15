#ifndef Lifter_H
#define Lifter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

#include <math.h>
#include "../RobotMap.h"
#include "../DataLogger.h"

#define DOWN 1 // FWD (Positive value)
#define UP -1 // REV (Negative value)

// Defined motor speeds
#define MAX_SPEED 			0.9
#define MANUAL_SPEED		0.7
#define MIN_SPEED			0.4
#define BRAKE_SPEED			0.1


class Lifter: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Lifter();

	Encoder* lifterEncoder;
	CANTalon* lifterMotor;

	void InitDefaultCommand();
	void Brake();
};

#endif
