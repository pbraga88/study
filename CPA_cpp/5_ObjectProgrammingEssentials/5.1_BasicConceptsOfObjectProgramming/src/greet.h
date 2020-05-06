#pragma once

#include <string>

class Greeting
{
  private:
    std::string name;
  public:
    Greeting();
    Greeting(std::string);

    ~Greeting();

    void SetName(std::string);
    void Greet();
};
