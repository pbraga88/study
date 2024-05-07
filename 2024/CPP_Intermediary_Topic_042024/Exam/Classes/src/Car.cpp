#include <iostream>
#include "Car.h"
#include "ABS.h"
#include "MotorManagement.h"

Car::Car()
{	
}

Car::~Car()
{
	for(auto &part:controller) {
		delete part;
	}
	controller.clear();
}

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