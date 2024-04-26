#pragma once
#include <iostream>
// #include "Image.h"

class Image;
class ProcessingStep {
public:
	ProcessingStep(){}
	~ProcessingStep(){}
	virtual bool Process(Image& image) const = 0;
};

class ContrastStep : public ProcessingStep {
	virtual bool Process(Image& image) const {
		(void) image;
		std::cout<<"ContrastStep processing"<<std::endl;
		return true;
	}
};

class BrightnessStep : public ProcessingStep {
	virtual bool Process(Image& image) const{
		(void) image;
		std::cout<<"BrightnessStep processing"<<std::endl;
		return true;
	}
};

