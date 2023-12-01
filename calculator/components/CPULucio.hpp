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

    std::vector<Digit> getDigits();
    int getDecimalPosition();

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

class CPULucio: public Cpu{
  private:
    Display* display;
    bool on = false;

  protected:

    virtual void clear();
    virtual void clearMemory();
    virtual void showBuffer(BufferDigits);

    Operator * currentOperator = nullptr;
    BufferDigits op1;
    BufferDigits op2;
    BufferDigits result;
    BufferDigits mem;

  public:
    Display* getDisplay() override;
    void setDisplay(Display*) override;
    
    void receiveDigit(Digit) override;
    void receiveOperator(Operator) override;
    void receiveControl(Control) override;

    void setOperator(Operator);

};