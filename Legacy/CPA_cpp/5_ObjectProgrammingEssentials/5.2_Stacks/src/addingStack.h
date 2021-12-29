#pragma once

#include "stack.h"

class AddingStack:Stack{
  private:
    int sum;
  public:
    AddingStack();
    ~AddingStack();
    void push(int value);
    int pop(void);
    int getSum(void);

};
