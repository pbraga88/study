#pragma once

class Classe{
  public:
    Classe(void);
    Classe(int value);
    Classe(Classe const&);
    ~Classe(void);
    int getValue(void);
    void setValue(int value);
    void mem_alloc(int memory);
  // private:
    int value;
    int x;
    int *mem;
};

class Classe_2{
  public:
    Classe_2(int val){value = val; }
  // private:
    int value;
};
