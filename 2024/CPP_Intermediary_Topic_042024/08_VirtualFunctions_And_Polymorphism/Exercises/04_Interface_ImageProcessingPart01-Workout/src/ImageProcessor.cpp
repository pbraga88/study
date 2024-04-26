#include "ImageProcessor.h"

ImageProcessor::ImageProcessor(void)
{
}

ImageProcessor::~ImageProcessor(void)
{
}

void ImageProcessor::Process(
	const ProcessingStep& aProcStep,
	Image& aImage)
{
	aProcStep.Process(aImage);
}

void ImageProcessor::ProcessSet(const std::vector<ProcessingStep*> procSet, Image& aImage) {
	for(auto &step : procSet) {
		step->Process(aImage);
	}
}

