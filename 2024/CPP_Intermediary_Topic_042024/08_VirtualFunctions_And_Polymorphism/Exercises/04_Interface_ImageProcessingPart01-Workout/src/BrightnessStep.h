#pragma once

#include "ProcessingStep.h"

class BrightnessStep :
	public ProcessingStep
{
public:
	BrightnessStep(void);
	virtual ~BrightnessStep(void);

	// Overrides ImageProcNode::Process
	virtual bool Process(Image& rImage) const;

private:
	// Copy constructor
	BrightnessStep(const BrightnessStep& r);

	// Assignment constructor
	BrightnessStep& operator=(const BrightnessStep& r);

};
