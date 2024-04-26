#pragma once

class Image;
class ProcessingStep
{
public:
	ProcessingStep(void);
	virtual ~ProcessingStep(void);

	virtual bool Process(Image& rImage) const = 0;

	// // Copy constructor
	// ProcessingStep (const ProcessingStep& r);

	// // Assignment constructor
	// ProcessingStep& operator=(const ProcessingStep& r);
private:

};