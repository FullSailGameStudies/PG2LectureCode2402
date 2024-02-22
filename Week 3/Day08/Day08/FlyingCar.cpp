#include "FlyingCar.h"

std::string FlyingCar::vehicleInformation()
{
    //Do we EXTEND the base version or do we FULLY OVERRIDE it?
    //if we EXTEND, we call the base method  (baseClassName::Method(...) )
    //if we FULLY OVERRIDE, we do NOT call the base method
    std::string flyingInfo = "I am a flying car. Welcome to the future.\nMax Altitude: " + std::to_string(maxAltitude_) + "\tMax Airspeed: " + std::to_string(maxAirspeed_) + "\n";
    return flyingInfo + Car::vehicleInformation();
}
