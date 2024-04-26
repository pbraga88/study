#pragma once
#include "IControl.h"

class ABS :
	public IControl
{
public:
	ABS(void);
	virtual ~ABS(void);
	virtual void Start();
	virtual void Stop();
	virtual bool IsStarted() const;
	
	static void ForceInError() { inError = true; }
	static void ClearError() { inError = false; }

private:
	bool isStarted = false;
	static bool inError;
};