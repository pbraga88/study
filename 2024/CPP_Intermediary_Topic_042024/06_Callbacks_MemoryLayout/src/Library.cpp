// #include "stdafx.h"
#include "Library.h"

static void* storeInstance = nullptr;
static int(*storefunctionPointer)(void* p) = nullptr;

void registerCallback(void *a, int(*funcPtr)(void* p))
{
    storeInstance = a;
    storefunctionPointer = funcPtr;
}

int DoCalculation()
{   
    //processing takes minutes
    if ((storefunctionPointer != nullptr) && (storeInstance != nullptr))
    {
        return storefunctionPointer(storeInstance);
    }
    return 0;
}