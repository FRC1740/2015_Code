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

	
	virtual void RobotInit()
	{
		CommandBase::init();
		printf("start of init\n");
		SmartDashboard::init(); // i guess we init the smart dash here.... idk where else to do it, idk if its necessary

		drivemodechooser = new SendableChooser();

		drivemodechooser->AddObject("Standard Tank Drive", new StandardTankDrive());
		drivemodechooser->AddObject("2 Joystick Mecanum", new MecanumTankDrive());
		drivemodechooser->AddDefault("3 Axis Drive (1 Joystick)", new ThreeAxisDrive());
		drivemodechooser->AddObject("3 Axis Xbox Drive", new XBoxDrive());
		SmartDashboard::PutData("Drive Mode", drivemodechooser);
		printf("added objects\n");
		autonomousCommand = new Autonomous();

		lw = LiveWindow::GetInstance();
		printf("Starting robot!\n");


		CameraServer::GetInstance()->SetQuality(100);
		CameraServer::GetInstance()->StartAutomaticCapture("cam0");

		compressor = new Compressor();

	}
	
	virtual void AutonomousInit()
	{
		compressor->Start();
		autonomousCommand->Start();
	}
	
	virtual void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TeleopInit()
	{
//		DataLogger *logger = new DataLogger();
//		logger->Log("Entering Telop\n", 2);
//		logger->~DataLogger();

		autonomousCommand->Cancel();
		teleopcommand = (Command *) drivemodechooser->GetSelected();
		teleopcommand->Start();
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

