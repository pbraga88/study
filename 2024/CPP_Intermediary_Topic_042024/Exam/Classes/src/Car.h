#pragma once
#include <vector>
#include "IControl.h"

class ABS;
class MotorManagement;
class Car
{
public:
	Car();
	~Car();

	void Start();
	void Stop();
	bool IsStarted() const;

	// void SetABS(ABS* abs);
	// void SetMotorManagement(MotorManagement* motorManagement);
	void processController(IControl* ctrl) {
		controller.push_back(ctrl);
	}

private:
	// MotorManagement* motorManagement = nullptr;
	// ABS*			 abs = nullptr;
	std::vector<IControl*> controller;
};
