#ifndef __EXERCISE_H__
#define __EXERCISE_H__
#include <iostream>
#include "Dog.h"


Dog test_dog();

#ifdef __cplusplus
extern "C" {
#endif
char *return_string();
}

#ifdef __cplusplus
}
#endif

#endif