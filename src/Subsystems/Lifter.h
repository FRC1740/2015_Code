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
	// The following methods are for testing and probably won't be employed in the 2015 'bot
	void Tilt(double speed);
	void TiltStop();
	void StopAll();
};

#endif
