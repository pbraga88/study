#include "ImageProcessor.h"

ImageProcessor::ImageProcessor()
{
}

ImageProcessor::~ImageProcessor()
{
}

void ImageProcessor::ProcessImage(
	const ProcessingStep& step,
	Image& aImage)
{
	step.Process(aImage);
}

