#include <Commands/Autos/BasicAuto.h>
#include "Commands/Autos/PickUpAndSkateAuto.h"
#include "Commands/Autos/PickUpAndPushAuto.h"
#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/Drive/StandardTankDrive.h"
#include "Commands/Drive/MecanumTankDrive.h"
#include "Commands/Drive/ThreeAxisDrive.h"
#include "Commands/Drive/XBoxDrive.h"
#include "CommandBase.h"



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
	// TODO can i initialize a pointer to datalogger here?
	Command *autonomousCommand;
	Command *teleopcommand;
	LiveWindow *lw;
	Compressor *compressor;
	SendableChooser *drivemodechooser;
	SendableChooser *autonomouschooser;
	
	virtual void RobotInit()
	{

//		logger->Log("RobotInit()", STATUS_MESSAGE);
		CommandBase::init();
//		SmartDashboard::init(); // i guess we init the smart dash here.... idk where else to do it, idk if its necessary

		drivemodechooser = new SendableChooser();
		drivemodechooser->AddObject("Standard Tank Drive", new StandardTankDrive());
		drivemodechooser->AddObject("2 Joystick Mecanum", new MecanumTankDrive());
		drivemodechooser->AddDefault("3 Axis Drive (1 Joystick)", new ThreeAxisDrive());
		drivemodechooser->AddObject("3 Axis Xbox Drive", new XBoxDrive());
		SmartDashboard::PutData("Drive Mode", drivemodechooser);

//		->Log("added objects", VERBOSE_MESSAGE);
		autonomouschooser = new SendableChooser();
		autonomouschooser->AddObject("Basic Auto: Drive Forward", new BasicAuto());
		autonomouschooser->AddObject("Fancy Auto: Grab and Skate with Box", new PickUpAndSkateAuto());
		autonomouschooser->AddDefault("Fancy Auto 2: Lift Trash Can, Push Box", new PickUpAndPushAuto());
		SmartDashboard::PutData("Autonomous", autonomouschooser);

		lw = LiveWindow::GetInstance();
//		->Log("Starting robot!", VERBOSE_MESSAGE);
//		->Flush();
		CameraServer::GetInstance()->SetQuality(100);
		CameraServer::GetInstance()->StartAutomaticCapture("cam0");

		compressor = new Compressor();

	}
	
	virtual void AutonomousInit()
	{
//		->Log("AutonomousInit()",STATUS_MESSAGE);
//		->Log("Starting Compressor", STATUS_MESSAGE);
		compressor->Start();
		autonomousCommand = (Command *) autonomouschooser->GetSelected();
		autonomousCommand->Start();
	}
	
	virtual void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TeleopInit()
	{
//		->Log("Entering TeleopInit()", STATUS_MESSAGE);
//		autonomousCommand->Cancel();
		teleopcommand = (Command *) drivemodechooser->GetSelected();
		teleopcommand->Start();
//		->End();
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

