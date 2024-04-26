#include <iostream>
#include "ABS.h"

bool ABS::inError = false;

ABS::ABS()
{
}

ABS::~ABS()
{
}

void ABS::Start()
{
	if (!ABS::inError) {
		isStarted = true;
	}
	std::cout << "Starting ABS System" << std::endl;
}


void ABS::Stop()
{
	isStarted = false;
	std::cout << "Stopping ABS System" << std::endl;
}

bool ABS::IsStarted() const
{
	return isStarted;
}

