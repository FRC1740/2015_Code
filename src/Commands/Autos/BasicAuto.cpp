#include "BasicAuto.h"

BasicAuto::BasicAuto()
{
	Move(0, .5, 5);
	Move(90, .5, 2);
	CalibrateLifter();
}
