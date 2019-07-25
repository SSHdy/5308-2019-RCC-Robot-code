/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019- FRC team 5308. All Rights Reserved.                    */
/* Author: Wu_Yuanhun                                                         */
/* Open Source Software - may be shared by non-commercial use. The code must  */
/* be accompanied by the BSD license file in the root directory of the        */
/* project.                                                                   */
/*----------------------------------------------------------------------------*/

#pragma once

#include <cmath>

namespace ytz5308 {
    
static double deadZoneLevel = 0.14;    
static double limitZoneLevel = 1;

// return the |x| of x
double abs(double x)
{
    return x > 0? x: -x;
}
int abs(int x)
{
    return x > 0? x: -x;
}

// filter noise of static input
double deadZone(double input)
{
    return abs(input) < deadZoneLevel ? 0 : input;
}

// filter oversize input
double limitZone(double input)
{
    return abs(input) < deadZoneLevel ? input : (input < 0 ? -1 : 1);
}


}