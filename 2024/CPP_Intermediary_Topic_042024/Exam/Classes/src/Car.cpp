#include <iostream>
#include "Car.h"
#include "ABS.h"
#include "MotorManagement.h"

Car::Car()
{	
}

Car::~Car()
{
	// delete abs; 
	// abs = nullptr;

	// delete motorManagement; 
	// motorManagement = nullptr;
	for(auto &part:controller) {
		delete part;
	}
	controller.clear();
}

// void Car::SetABS(ABS* a_abs) 
// {
// 	abs = a_abs;
// }
// void Car::SetMotorManagement(MotorManagement* a_motorManagement)
// {
// 	motorManagement = a_motorManagement;
// }

void Car::Start()
{
	for(auto &part:controller) {
		part->Start();
	}
}

void Car::Stop() 
{
	for(auto &part:controller) {
		part->Stop();
	}
}

bool Car::IsStarted() const
{
	for(auto &part:controller) {
		if(!part->IsStarted()){
			return false;
		}
	}
	return true;
}