#pragma once

#include <vector>
#include <string>
#include "CalculatorInterfaces.hpp"

class BufferDigits{
  private:
    std::vector<Digit> digits;
    int decimalPosition;

  public:
    int digitToInt(Digit);
    void addDigit(Digit);
    void setDecimalSeparator();

    // Obtém o valor armazenado dentro do buffer
    float getValue();


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