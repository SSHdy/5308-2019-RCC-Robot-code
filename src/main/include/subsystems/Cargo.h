/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>

#include <rev/CANSparkMax.h>
#include <rev/CANEncoder.h>
#include <ctre/Phoenix.h>

#include "RobotMap.h"


#include "commonLib/yTools.h"

using namespace ytz5308;

typedef rev::CANSparkMaxLowLevel::MotorType revMotor;

class Cargo : public frc::Subsystem
{
private:

std::shared_ptr<rev::CANSparkMax> csm_arm_main;
std::shared_ptr<rev::CANSparkMax> csm_arm_sub;

std::shared_ptr<rev::CANEncoder> cane_arm;

std::shared_ptr<rev::CANSparkMax> csm_intake_mac;
std::shared_ptr<VictorSPX>        vct_intake_btm;

public:
  Cargo();
  void InitDefaultCommand() override;
  void Periodic() override;
};