#pragma once

#include "ProcessingStep.h"

class ContrastStep :
	public ProcessingStep
{
public:
	ContrastStep (void);
	virtual ~ContrastStep (void);

	// Overrides ImageProcNode::Process
	virtual bool Process(Image& rImage) const;

private:
	// Copy constructor
	ContrastStep (const ContrastStep & r);

	// Assignment constructor
	ContrastStep& operator=(const ContrastStep& r);
};
