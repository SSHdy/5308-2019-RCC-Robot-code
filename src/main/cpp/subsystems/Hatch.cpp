/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Hatch.h"

Hatch::Hatch() : Subsystem("Hatch") 
{
  sol_hatch.reset(new frc::DoubleSolenoid(kPCMPort, kHatchSolF, kHatchSolB));
  polit.reset(new frc::Joystick(kPolit));
}

void Hatch::InitDefaultCommand()
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Hatch::solReverse()
{
  sol_hatch -> Set( (frc::DoubleSolenoid::Value) (3 - sol_hatch->Get())); 
  printf("hatch solenoid change to ");
  printf(sol_hatch->Get()-1?"Forward\n":"Reversed\n");
}

void Hatch::Periodic()
{
  if(polit->GetRawButtonPressed(3))
  {
    solReverse(); 
  }
}//hatch还有一个compressor
//compressor 是所有气动共享的
//然后根据我们以前的经验，subsystem中要做到没有depend关系//
//（这里指一个subsystem使用另外一个subsystem的变量/函数等）
//就是要相对独立，不然很容易出事
// clear?(y/n):那compressor就只用在pneumatic里面定义了就可以了吗
// 对，应为compressor一般就是开场start
//让它自个儿转就行
//但是因为compressor很耗电，容易抢电机电压，
//所以我们会设置个键位来关它/开它（在有些时候单场比赛后期，车跑不动了，关compressor提高车速等等）
//所以如果后期跑不动的话就关compressor，就是运行那个compressordisable？
//对对对，绑个键就行了，一般会帮在不常用键位
//但是如果compressor被关了的话，hatch和爬升怎么办
// 气瓶是会储存气压对
// compressor的工作方式就是有一个range 从气压比如20 - 30（数据瞎编的）
// 当气压低于20compressor开始打气
//，快到30自己停止//
//但是气压在17其实还是可以用的
//每调整一次电磁阀状态，就会用掉一部分气压
// 我先关电脑了，有问题发群里 ok？:
//让我截几个图免得忘记
//我等下把这个继续更新github
// 最好每个项目写了就push上去但是我会把这段备注删了，你直接复制发群里
// 复制好了你就删掉这段