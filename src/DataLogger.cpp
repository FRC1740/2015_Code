/*
 * DataLogger.cpp
 *
 *  Created on: Feb 3, 2015
 *      Author: CEstabrooks
 */

#include "DataLogger.h"

DataLogger::DataLogger()
{
	// TODO Auto-generated constructor stub
	strcpy(logfile, "/media/sda1/log.txt"); // Log file name
	fh = fopen(logfile, "w+");
	if (fh != NULL)
		fwrite((void *)"Created Log File\n", sizeof(char), 17, fh);
	else
		abort = true;
}

int DataLogger::Log(const char *data, int level)
{

	if (abort)
		return(-1);

	int writeCount;

	if (level <= DEBUG_LEVEL)
	{
		strcpy(buffer, data);
		strcat(buffer, "\n");
		writeCount = fwrite((void *)buffer, sizeof(char), strlen(buffer), fh);
	}
	else
		writeCount = 0;

	return(writeCount);
}
void DataLogger::Flush()
{
	fflush(fh);
}
int DataLogger::End()
{
	if (abort)
		return(-1);

	int error=0;
	error = fclose(fh);
	return(error);
}
