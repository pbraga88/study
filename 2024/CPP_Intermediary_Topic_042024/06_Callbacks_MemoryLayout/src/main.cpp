// #include "stdafx.h"
#include <iostream>
#include <functional>
#include "Library.h"
#include <cfloat>
#include <cstdlib>
	

using namespace std;


void callme() {
    cout << "Congratulations, you have called callme()" << endl;
}

float nextHigherFloat(float value) {
    return value + FLT_EPSILON;
}

class CgiveMeAValue
{
public:
    int callmeInAClass()
    {
        std::cout<<"Trampolim callback just called me!"<<std::endl;
        return std::rand();
    }

    static int trampolim(void* callback) {
        CgiveMeAValue* callback_function = static_cast<CgiveMeAValue*>(callback);
        return callback_function->callmeInAClass();
    }

};

void caller(void(*fptr)()) {
    fptr();
}

float call_float(float(*fptr)(float), float f) {
    // nextHigherFloat(x); //WRONG
    return fptr(f);
}

int main()
{
    //STEP 0:
    // implement an additional function that takes in as argument a function pointer to a function with no argument and returning void
    // call your new function and pass it the "callme" function
    
    //add your magic here
    caller(&callme);

//  --> Implement above and move this to the next step when it compiles and runs correctly
    //STEP 1:
    float f = 1.0;
    std::cout<<f<<std::endl;
    // cout << "float value: " << std::hexfloat << f << endl;
    // Implement an additional function that takes in as argument a function pointer to a function with an float as argument and returns a float.
    // Call your new function and pass it the "nextHigherFloat" function. Also, pass it parameter f and store the result in f
    // Store the returned value and print it
    
    //add your magic here
    f = call_float(&nextHigherFloat, f);
    cout << "float value: " << std::hexfloat << f << endl;

    //STEP 2:
    // Call the function 'callmeInAClass', but don't call it directly, 
    // Call it by providing the object (aValue) as void* argument to a static function that is added to the class CgiveMeAValue
    CgiveMeAValue aValue;
    int someRandomValue = -1;
    //make the static function in CgiveMeAValue
    //call the static function and provide aValue as object, store the result in someRandomValue
    
    //add your magic here
    someRandomValue = CgiveMeAValue::trampolim(&aValue);
    cout << "received value: " << someRandomValue << endl;

    //STEP 3:
    // use Library.h: use the registerCallback function to register the object (aValue) and ensure callmeInAClass function is called
    int anotherReturnedRandomValue = -1;
    
    //add your magic here
    registerCallback(&aValue, &CgiveMeAValue::trampolim); // Register callback

    anotherReturnedRandomValue = DoCalculation(); // Call lib function which will call
                                                  // 'callmeInAClass' function

    cout << "received value: " << anotherReturnedRandomValue << endl;
/**/

    return 0;
}
