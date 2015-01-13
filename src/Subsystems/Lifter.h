#ifndef Lifter_H
#define Lifter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANTalon.h"

class Lifter: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon* liftMotor;
	CANTalon* tiltMotor;
public:
	Lifter();
	void InitDefaultCommand();
	void Raise();
	void Lower();
	void Stop();
	void TiltForward();
	void TiltBack();
	void TiltStop();
	void StopAll();
};

#endif
