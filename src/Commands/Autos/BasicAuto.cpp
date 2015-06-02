#include "BasicAuto.h"

BasicAuto::BasicAuto()
{
	AddSequential(new Move(0, .5, 5)); // move at 0 degrees (forward) at half speed for 5 seconds
}
