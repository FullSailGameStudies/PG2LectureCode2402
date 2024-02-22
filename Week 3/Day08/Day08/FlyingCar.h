#pragma once
#include "Car.h"
#include <iostream>

class FlyingCar : public Car
{
public:
	//the base ctor will get called first then the code for the 
	// derived ctor will execute
	// 
	//the child ctor MUST call a base ctor
	FlyingCar(int year, std::string make, std::string model,
			  int maxAlt, int maxAirspeed) 
		: Car(year, make, model), 
		maxAltitude_(maxAlt), 
		maxAirspeed_(maxAirspeed)
	{
		//std::cout << std::to_string(mModelYear) << " " << mMake << " " << mModel;
	}

	std::string vehicleInformation() override;//override keyword is optional

private:
	int maxAltitude_, maxAirspeed_;
};

