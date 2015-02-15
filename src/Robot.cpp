#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/StandardTankDrive.h"
#include "Commands/MecanumTankDrive.h"
#include "Commands/ThreeAxisDrive.h"
#include "Commands/XBoxDrive.h"
#include "Commands/Autonomous.h"
#include "Commands/Grab.h"
#include "Commands/Release.h"
#include "CommandBase.h"
#include "DataLogger.h"


/* 
 *	Team 1740
 *	2015 Code
 *	Programming Staff:
 *	Lord Kevin "Hjax" Konrad: High Overlord of Programming and Python / C++ grand master
 *	Sire Henry Crain: Majordomo of Programming and Python / C++ master
 *	Lady Allison "armadillokake" Konrad: Queen of the Armadillos and C++ n00b
 *	Sir Jonathan Lei: Python / C++ dude
 *	Our Lord, Charles Estabrooks: Programming God and C / C++ savior
 *	Brian Healy the Eternal Champion: Programming God and Labview / TI-89 grand master
 */

class CommandBasedRobot : public IterativeRobot {
private:
	Command *autonomousCommand;
	Command *teleopcommand;
	LiveWindow *lw;
	Compressor *compressor;
	Command *grabCommand, *releaseCommand, *raiseCommand, *lowerCommand;
	SendableChooser *drivemodechooser;
	DataLogger *logger;
	
	virtual void RobotInit()
	{
		logger = new DataLogger();
		logger->Log("RobotInit()", STATUS_MESSAGE);
		CommandBase::init(logger);
//		SmartDashboard::init(); // i guess we init the smart dash here.... idk where else to do it, idk if its necessary

		drivemodechooser = new SendableChooser();

		drivemodechooser->AddObject("Standard Tank Drive", new StandardTankDrive(logger));
		drivemodechooser->AddObject("2 Joystick Mecanum", new MecanumTankDrive(logger));
		drivemodechooser->AddDefault("3 Axis Drive (1 Joystick)", new ThreeAxisDrive(logger));
		drivemodechooser->AddObject("3 Axis Xbox Drive", new XBoxDrive(logger));
		SmartDashboard::PutData("Drive Mode", drivemodechooser);
		logger->Log("added objects", VERBOSE_MESSAGE);
		autonomousCommand = new Autonomous();

		lw = LiveWindow::GetInstance();
		logger->Log("Starting robot!", VERBOSE_MESSAGE);
		logger->Flush();
		CameraServer::GetInstance()->SetQuality(100);
		CameraServer::GetInstance()->StartAutomaticCapture("cam0");

		compressor = new Compressor();

	}
	
	virtual void AutonomousInit()
	{
		logger->Log("AutonomousInit()",STATUS_MESSAGE);
		logger->Log("Starting Compressor", STATUS_MESSAGE);
		compressor->Start();
		autonomousCommand->Start();
	}
	
	virtual void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TeleopInit()
	{
		logger->Log("Entering TeleopInit()", STATUS_MESSAGE);
		autonomousCommand->Cancel();
		teleopcommand = (Command *) drivemodechooser->GetSelected();
		teleopcommand->Start();
//		logger->End();
	}
	
	virtual void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(CommandBasedRobot);

