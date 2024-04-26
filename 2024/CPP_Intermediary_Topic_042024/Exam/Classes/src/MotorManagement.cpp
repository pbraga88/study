#include <iostream>
#include "MotorManagement.h"


MotorManagement::MotorManagement(void)
{
}
MotorManagement::~MotorManagement(void)
{
}

void MotorManagement::Start()
{
	isStarted = true;
	std::cout << "Starting MotorManagement System" << std::endl;
}


void MotorManagement::Stop()
{
	isStarted = false;
	std::cout << "Stopping MotorManagement System" << std::endl;
}

bool MotorManagement::IsStarted() const
{
	return isStarted;
}
