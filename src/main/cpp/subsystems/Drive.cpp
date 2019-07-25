/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Drive.h"

Drive::Drive() : Subsystem("ExampleSubsystem")
{

  //init sparkmax left
  csm_left_frot.reset(new rev::CANSparkMax(kCsmLeftFrot, revMotor::kBrushless));
  csm_left_midd.reset(new rev::CANSparkMax(kCsmLeftMidd, revMotor::kBrushless));
  csm_left_back.reset(new rev::CANSparkMax(kCsmLeftBack, revMotor::kBrushless));

  //init sparkmax right 
  csm_rght_frot.reset(new rev::CANSparkMax(kCsmRghtFrot, revMotor::kBrushless));
  csm_rght_midd.reset(new rev::CANSparkMax(kCsmRghtMidd, revMotor::kBrushless));
  csm_rght_back.reset(new rev::CANSparkMax(kCsmRghtBack, revMotor::kBrushless));

  //set inverted
  csm_left_midd -> SetInverted(true);
  csm_rght_midd -> SetInverted(true);

  //init speed controller group
  scg_left = std::make_shared<frc::SpeedControllerGroup>(*csm_left_frot,*csm_left_midd,*csm_rght_back));
  scg_rght = std::make_shared<frc::SpeedControllerGroup>(*csm_rght_frot,*csm_rght_midd,*csm_rght_back));

  drive_base.reset(new frc::DifferentialDrive(*scg_left,*scg_rght));

  polit.reset(new frc::Joystick(kPolit));
}

void Drive::InitDefaultCommand()
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Drive::Periodic()
{
  drive_base -> ArcadeDrive( deadZone(polit->GetY()) , deadZone(polit->GetX()) );
}