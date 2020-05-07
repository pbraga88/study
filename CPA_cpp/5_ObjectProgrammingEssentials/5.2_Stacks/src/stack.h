#pragma once

#include <string>

class Stack{
  private:
    int stackstore[100];
    int SP;
  public:
    Stack(void);
    void push(int val);
    int pop(void);
    ~Stack();
};
