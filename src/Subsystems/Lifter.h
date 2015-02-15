#ifndef Lifter_H
#define Lifter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

#include <math.h>
#include "../RobotMap.h"
#include "../DataLogger.h"

#define DOWN 1 // FWD (Positive value)
#define UP -1 // REV (Negative value)

// speeds for various distances away from the target point
#define MAX_SPEED 			0.9
#define HIGH_MIDDLE_SPEED 	0.8
#define LOW_MIDDLE_SPEED 	0.65
#define LOW_SPEED			0.5
#define MIN_SPEED			0.4
#define BRAKE_SPEED		0.1

class Lifter: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Lifter(DataLogger* logger);

	Encoder* lifterEncoder;
	CANTalon* lifterMotor;
	DataLogger *l=NULL;

	void InitDefaultCommand();
	void GoToPoint(int);
	void Calibrate();
	void Brake();
};

#endif
