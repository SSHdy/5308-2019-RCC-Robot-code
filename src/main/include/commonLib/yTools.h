/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019- FRC team 5308. All Rights Reserved.                    */
/* Author: Wu_Yuanhun                                                         */
/* Open Source Software - may be shared by non-commercial use. The code must  */
/* be accompanied by the BSD license file in the root directory of the        */
/* project.                                                                   */
/*----------------------------------------------------------------------------*/

#pragma once

namespace ytz5308 {

// return the |x| of x
double abs(double);

// filter noise of static input
double deadZone(double);

// filter oversize input
double limitZone(double);

}
