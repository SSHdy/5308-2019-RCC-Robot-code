/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Pneumatics.h"

Pneumatics::Pneumatics() : Subsystem("ExampleSubsystem") 
{
  compressor.reset(new frc::Compressor(kPCMPort));

  CompreesorEnable();
}

void Pneumatics::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Pneumatics::CompreesorEnable()
{
  compressor->Start();
  printf("Compressor Start\n");
}

void Pneumatics::CompressorDisable() 
{
  compressor->Stop();
  printf("Compressor Stop\n");
}
