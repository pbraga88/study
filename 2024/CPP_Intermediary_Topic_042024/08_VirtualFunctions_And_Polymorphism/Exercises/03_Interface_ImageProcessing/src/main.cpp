#include "Image.h"
#include "ImageProcessor.h"
#include "ProcessingStep.h"

int main(void)
{	
	// const ProcessingStep* processB = new BrightnessStep;
	// const ProcessingStep* processC = new ContrastStep;

	BrightnessStep bstep;
	ContrastStep cstep;

	Image image;
	ImageProcessor iprocessor;

	// iprocessor.ProcessImage(*processB, image);
	// iprocessor.ProcessImage(*processC, image);

	iprocessor.ProcessImage(bstep, image);
	iprocessor.ProcessImage(cstep, image);

	return 0;
}