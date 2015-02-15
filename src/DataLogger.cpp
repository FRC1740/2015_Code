/*
 * DataLogger.cpp
 *
 *  Created on: Feb 3, 2015
 *      Author: CEstabrooks
 */

#include "DataLogger.h"

DataLogger::DataLogger()
{
	printf("starting data logger\n");
	strcpy(logfile, "/media/sda1/log_"); // Log file name
	currentTime=time(0);
	char now[256];
	sprintf(now, "%ld", currentTime);
	strcat(logfile, now);
	strcat(logfile, ".txt");
	printf(logfile);
	fh = fopen(logfile, "w+");
	if (fh != NULL)
	{
		fwrite((void *)"Created Log File\n", sizeof(char), 17, fh);
		fclose(fh);
		abort=false; // initialized to true in header file
	}
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
		if (strcmp(buffer, bufferPrevious) != 0)
		{
			fh = fopen(logfile, "a");
			if (fh != NULL)
			{
				writeCount = fwrite((void *)buffer, sizeof(char), strlen(buffer), fh);
				fclose(fh);
			}
			else abort = true;

			fprintf(stderr, buffer);
			strcpy(bufferPrevious, buffer);
		}
	}
	else
		writeCount = 0;

	return(writeCount);
}
void DataLogger::Flush()
{
//	fflush(fh);
}
int DataLogger::End()
{
	if (abort)
		return(-1);

	int error=0;
//	error = fclose(fh);
	return(error);
}
