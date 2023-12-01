#pragma once

#include <vector>
#include <string>
#include <math.h>
#include "CalculatorInterfaces.hpp"

class BufferDigits{
  private:
    std::vector<Digit> digits;
    int decimalPosition;

  public:
    static int digitToInt(Digit);
    static Digit intToDigit(int);
    
    BufferDigits();
    BufferDigits(float value);
    void addDigit(Digit);
    void setDecimalSeparator();
    void clear();
    float getValue();
	  void setValue(float value);
    void print();

    BufferDigits sqrt();
    BufferDigits percent();
    BufferDigits operator+(BufferDigits other);
    BufferDigits operator-(BufferDigits other);
    BufferDigits operator/(BufferDigits other);
    BufferDigits operator*(BufferDigits other);

};

class CpuLucio: public Cpu{
  private:
    Display* display;
    

  public:
    Display* getDisplay();
    void setDisplay(Display*);
    void receiveDigit(Digit);
    void receiveOperator(Operator*);
    void receiveControl(Control);
    void setOperator(Operator);

    protected:
     Operator * currentOperator = nullptr;
	   BufferDigits op1;
     BufferDigits op2;
     BufferDigits result;
     BufferDigits mem;
     

};