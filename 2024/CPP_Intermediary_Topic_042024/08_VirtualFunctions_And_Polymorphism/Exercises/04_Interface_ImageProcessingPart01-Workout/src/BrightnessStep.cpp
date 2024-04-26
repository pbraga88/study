#include <iostream>
#include "BrightnessStep.h"
#include "Image.h"

BrightnessStep::BrightnessStep(void)
{
}

BrightnessStep::~BrightnessStep(void)
{
}

bool BrightnessStep::Process(Image& rImage) const
{
	std::cout << "Executing BrightnessStep::Process.." << std::endl;
	rImage.setBright();
	return true;
}
