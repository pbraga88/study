// Classes.cpp : Defines the entry point for the console application.
//

#define YAFFUT_MAIN

#include "yaffut.h"
#include <list>
#include <algorithm>
#include "CarBuilder.h"
#include "Car.h"
#include "ABS.h"

FUNC(CarBuilderTest)
{
	Car* pCar = CarBuilder::Build();

	YAFFUT_NOT_NULL(pCar);

	pCar->Start();
	YAFFUT_EQUAL(pCar->IsStarted(), true);

	pCar->Stop();
	YAFFUT_EQUAL(pCar->IsStarted(), false);

	ABS::ForceInError();

	pCar->Start();
	YAFFUT_EQUAL(pCar->IsStarted(), false);

	pCar->Stop();
	YAFFUT_EQUAL(pCar->IsStarted(), false);

	ABS::ClearError();
	pCar->Start();
	YAFFUT_EQUAL(pCar->IsStarted(), true);

	pCar->Stop();
	YAFFUT_EQUAL(pCar->IsStarted(), false);
}

