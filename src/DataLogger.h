/*
 * DataLogger.h
 *
 *  Created on: Feb 3, 2015
 *      Author: CEstabrooks
 */

#ifndef DATALOGGER_H_
#define DATALOGGER_H_

#include <timer.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "WPILib.h"

/* Debugging Levels for logging
 * 0: Silent
 * 1: Error Messages
 * 2: Status Messages
 * 3: [unassigned]
 * 4: Verbose
 */
#define ERROR_MESSAGE 1
#define STATUS_MESSAGE 2
#define VERBOSE_MESSAGE 4

#define DEBUG_LEVEL 4 // Messages with this level or below will be logged

class DataLogger
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	// however the motors are public since its clearer to directly control the motors instead of having individual set functions
	Timer gameTime;
	FILE *fh;
	int abort=false;
	char logfile[256];
	char buffer[256];

public:
	DataLogger();
	int Log(const char *, int level);
	void Flush();
	int End();
};

#endif /* DATALOGGER_H_ */
