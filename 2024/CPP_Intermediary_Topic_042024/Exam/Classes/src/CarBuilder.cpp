#include <iostream>
#include "CarBuilder.h"
#include "Car.h"
#include "MotorManagement.h"
#include "ABS.h"
#include "IControl.h"

Car* CarBuilder::Build() 
{
	Car* car = new Car();

	car->processController(new MotorManagement);
	car->processController(new ABS);
	return car;
}
