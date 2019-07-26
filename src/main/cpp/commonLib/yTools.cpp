#include "commonLib/ytools.h"

namespace ytz5308 {

// return the |x| of x
double abs(double x)
{
    return x > 0? x: -x;
}

// filter noise of static input
double deadZone(double input)
{
    double deadZoneLevel = 0.14; 
    return abs(input) < deadZoneLevel ? 0 : input;
}

// filter oversize input
double limitZone(double input)
{
    double limitZoneLevel = 1;
    return abs(input) < limitZoneLevel ? input : (input < 0 ? -1 : 1);
}
}