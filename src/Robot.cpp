#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/StandardTankDrive.h"
#include "Commands/MecanumTankDrive.h"
#include "Commands/ThreeAxisDrive.h"
#include "Commands/Autonomous.h"
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
	Command *autonomousCommand;
	Command *teleopcommand;
	LiveWindow *lw;

	SendableChooser *drivemodechooser;

	
	virtual void RobotInit() {
		CommandBase::init();

		SmartDashboard::init(); // i guess we init the smart dash here.... idk where else to do it, idk if its necessary

		drivemodechooser = new SendableChooser();

		drivemodechooser->AddDefault("Standard Tank Drive", new StandardTankDrive());
		drivemodechooser->AddObject("2 Joystick Mecanum", new MecanumTankDrive());
		drivemodechooser->AddObject("3 Axis Drive (1 Joystick)", new ThreeAxisDrive());

		autonomousCommand = new Autonomous();

		lw = LiveWindow::GetInstance();
		printf("Starting robot!\n");

	}
	
	virtual void AutonomousInit() {
		autonomousCommand->Start();
	}
	
	virtual void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TeleopInit() {
		autonomousCommand->Cancel();
		teleopcommand = (Command *) drivemodechooser->GetSelected();
		teleopcommand->Start();
	}
	
	virtual void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TestPeriodic() {
		lw->Run();
	}
};

START_ROBOT_CLASS(CommandBasedRobot);

