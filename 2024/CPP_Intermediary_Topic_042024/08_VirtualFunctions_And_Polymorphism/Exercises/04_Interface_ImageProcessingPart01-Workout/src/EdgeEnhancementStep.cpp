#include <iostream>
#include "EdgeEnhancementStep.h"
#include "Image.h"

EdgeEnhancementStep::EdgeEnhancementStep()
{}
EdgeEnhancementStep::~EdgeEnhancementStep()
{}

bool EdgeEnhancementStep::Process(Image& rImage) const {
	std::cout << "Executing EdgeEnhancementStep::Process.." << std::endl;
    rImage.setEdge();
	return true;
}