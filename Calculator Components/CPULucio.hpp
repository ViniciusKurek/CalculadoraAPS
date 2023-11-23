#pragma once

#include <vector>
#include "CalculatorInterfaces.hpp"

class BufferDigits{
  private:
    std::vector<Digit> digits;
    int  decimalPosition;
    

  public:
    void addDigit(Digit);
    void setDecimalSeparator();

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
     BufferDigits mem;
     

};