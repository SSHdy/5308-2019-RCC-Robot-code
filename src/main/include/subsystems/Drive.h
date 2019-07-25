/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>

#include <rev/CANSparkMax.h>
#include <rev/CANEncoder.h>

#include "RobotMap.h"

#include "commonLib/yTools.h"

using namespace ytz5308;

typedef rev::CANSparkMaxLowLevel::MotorType revMotor;

class Drive : public frc::Subsystem
{
private:
  std::shared_ptr<rev::CANSparkMax> csm_left_frot;
  std::shared_ptr<rev::CANSparkMax> csm_left_midd;
  std::shared_ptr<rev::CANSparkMax> csm_left_back;

  std::shared_ptr<rev::CANSparkMax> csm_rght_frot;
  std::shared_ptr<rev::CANSparkMax> csm_rght_midd;
  std::shared_ptr<rev::CANSparkMax> csm_rght_back;

  std::shared_ptr<frc::SpeedControllerGroup> scg_left;
  std::shared_ptr<frc::SpeedControllerGroup> scg_rght;

  std::shared_ptr<frc::DifferentialDrive> drive_base;

  std::shared_ptr<rev::CANEncoder> cane_left;
  std::shared_ptr<rev::CANEncoder> cane_rght;

  std::shared_ptr<frc::Joystick> polit;

public:
  Drive();
  void InitDefaultCommand() override;
  void Periodic() override;
};