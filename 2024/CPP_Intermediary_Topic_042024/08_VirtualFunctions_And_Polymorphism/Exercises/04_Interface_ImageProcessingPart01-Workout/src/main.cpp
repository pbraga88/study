#include <iostream>
#include "ImageProcessor.h"
#include "ContrastStep.h"
#include "BrightnessStep.h"
#include "EdgeEnhancementStep.h"
#include "Image.h"
#include <vector>

int main(void)
{
	ImageProcessor ip;
	Image          image;
	// ProcessingStep procStep; // Not possible to instantiate pure virtual class
	ContrastStep   contrastStep;
	BrightnessStep brightnessStep;
	EdgeEnhancementStep edgeenhancementstep;

	// ip.Process(procStep, image);
	ip.Process(contrastStep, image);
	ip.Process(edgeenhancementstep, image);
	ip.Process(contrastStep, image);
	ip.Process(brightnessStep, image);
	std::cout<<std::endl;

	std::vector<ProcessingStep*> multiple_steps {&contrastStep, &edgeenhancementstep, 
												 &contrastStep, &brightnessStep};
	ip.ProcessSet(multiple_steps, image);
	std::cout<<std::endl;

	ProcessingStep *pStepContrast = new ContrastStep;
	ProcessingStep *pStepBrightness = new BrightnessStep;
	ProcessingStep *pStepEdgeEnhancement = new EdgeEnhancementStep;
	//
	const std::vector<ProcessingStep*> vStep {pStepContrast, pStepEdgeEnhancement,
											  pStepContrast, pStepBrightness};
	ip.ProcessSet(vStep, image);
	std::cout<<std::endl;

	// Get image settings
	std::cout<<"Image Bright: "<<image.getBright()<<std::endl;
	std::cout<<"Image Contrast: "<<image.getContrast()<<std::endl;
	std::cout<<"Image Edge: "<<image.getEdge()<<std::endl;

	return 0;
}