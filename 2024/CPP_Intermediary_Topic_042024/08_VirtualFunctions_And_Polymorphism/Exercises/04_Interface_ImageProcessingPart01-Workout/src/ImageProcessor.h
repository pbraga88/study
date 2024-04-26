#pragma once
#include <set>
#include <vector>
#include "ProcessingStep.h"

class ImageProcessor
{
public:
	ImageProcessor();
	~ImageProcessor();

	void Process(const ProcessingStep& aProc, Image& aImage);
	void ProcessSet(const std::vector<ProcessingStep*> procSet, Image& aImage);
};
