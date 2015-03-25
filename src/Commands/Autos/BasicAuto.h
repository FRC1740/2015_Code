#ifndef BasicAuto_H
#define BasicAuto_H

#include "Commands/CommandGroup.h"
#include "../Drive/DriveCommands/Move.h"
#include "../Lifter/CalibrateLifter.h"
#include "WPILib.h"

class BasicAuto: public CommandGroup
{
public:
	BasicAuto();
};

#endif
