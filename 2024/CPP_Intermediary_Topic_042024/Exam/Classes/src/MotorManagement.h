#pragma once
#include "IControl.h"

class MotorManagement :
	public IControl
{
public:
	MotorManagement(void);
	virtual ~MotorManagement(void);
	virtual void Start();
	virtual void Stop();
	virtual bool IsStarted() const;

private:
	bool isStarted = false;
};