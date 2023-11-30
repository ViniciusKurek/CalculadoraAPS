#pragma once

#include <vector>
#include <string>
#include "CalculatorInterfaces.hpp"

class BufferDigits{
  private:
    std::vector<Digit> digits;
    int decimalPosition;

  public:
    static int digitToInt(Digit);
    static Digit intToDigit(int);
    void addDigit(Digit);
    void setDecimalSeparator();
    void clear();
    // Obtém o valor armazenado dentro do buffer
    float getValue();

	  void setValue(float value);

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