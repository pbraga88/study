#pragma once

#include "ProcessingStep.h"
#include "Image.h"

class ImageProcessor
{
public:
	ImageProcessor();
	~ImageProcessor();

	void ProcessImage(const ProcessingStep& step, Image& aImage);
};
