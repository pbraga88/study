#include <iostream>
#include "ContrastStep.h"
#include "Image.h"

ContrastStep::ContrastStep(void)
{
}

ContrastStep::~ContrastStep(void)
{
}

bool ContrastStep::Process(Image& rImage) const
{
	std::cout << "Executing ContrastStep::Process.." << std::endl;
	rImage.setContrast();
	return true;
}
