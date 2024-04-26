#pragma once
#include "ProcessingStep.h"

class EdgeEnhancementStep:
    public ProcessingStep
{
public:
    EdgeEnhancementStep();
    virtual ~EdgeEnhancementStep();

    // Override ProcessingStep::Process
    virtual bool Process(Image& rImage) const;
private:
    // Copy contructor
    EdgeEnhancementStep(const EdgeEnhancementStep& rhs);

    // Overload assignment operator '='
    EdgeEnhancementStep operator=(const EdgeEnhancementStep& rhs);
};

