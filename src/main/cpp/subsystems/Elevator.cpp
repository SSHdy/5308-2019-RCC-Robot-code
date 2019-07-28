/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Elevator.h"

Elevator::Elevator() : Subsystem("Elevator") 
{

  polit.reset(new frc::Joystick(0));

  sol_ele.reset(new frc::DoubleSolenoid(kPCMPort, kEleF, kEleB));

}

void Elevator::InitDefaultCommand() 
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Elevator::Periodic()
{
  if(polit -> GetRawButtonPressed(-1))
  {
    sol_ele->Set(frc::DoubleSolenoid::Value::kForward);
  }
  else if(polit -> GetRawButtonPressed(-1))
  {
    sol_ele->Set(frc::DoubleSolenoid::Value::kReverse);
  }
  else if(polit -> GetRawButtonPressed(-1))
  {
    sol_ele->Set(frc::DoubleSolenoid::Value::kOff);
  }
}