/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Cargo.h"

Cargo::Cargo() : Subsystem("CargoSubsystem")
{
  intakeInNeoSpeed = 0.6;
  intakeIn775Speed = 0.6;

  //init Arm
  csm_arm_main.reset(new rev::CANSparkMax(kCsmArmMain, revMotor::kBrushless));
  csm_arm_sub .reset(new rev::CANSparkMax(kCsmArmSub, revMotor::kBrushless));
  cane_arm.reset(new rev::CANEncoder(*csm_arm_main));

  csm_arm_sub->SetInverted(true);

  scg_arm = std::make_shared<frc::SpeedControllerGroup>(*csm_arm_main, *csm_arm_sub);

  //init Intake
  csm_intake_mac.reset(new rev::CANSparkMax(kCsmIntakeMac, revMotor::kBrushless));
  vct_intake_btm.reset(new VictorSPX(kVctIntakeBtm));

  polit.reset(new frc::Joystick(kPolit));
}

void Cargo::takein()
{
  csm_intake_mac->Set(intakeInNeoSpeed);
  vct_intake_btm->Set(ctreMotor::PercentOutput, intakeIn775Speed);
}

void Cargo::takeout()
{
  csm_intake_mac->Set(-intakeInNeoSpeed);
  vct_intake_btm->Set(ctreMotor::PercentOutput, -intakeIn775Speed);
}

void Cargo::InitDefaultCommand()
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Cargo::Periodic()
{
  if(polit -> GetRawButton(3))
  {
    takein();
  }
  else if(polit -> GetRawButton(2))
  {
    takeout();
  }

}