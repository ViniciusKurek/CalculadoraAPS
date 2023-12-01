#pragma once

#include <vector>
#include <string>
#include <math.h>
#include "CalculatorInterfaces.hpp"

class BufferDigits{
  private:
    std::vector<Digit> digits;
    int decimalPosition;
    bool decimalLocked = false;
    bool isNegative = false;

  public:
    static int digitToInt(Digit);
    static Digit intToDigit(int);
    
    BufferDigits();
    BufferDigits(float value);

    std::vector<Digit> getDigits();
    int getDecimalPosition();

    void addDigit(Digit);
    void setDecimalSeparator();
    void setNegative(bool);
    bool getNegative();
    void clear();
    float getValue();
	  void setValue(float value);
    void print();
    bool isEmpty();
    void setZero();

    BufferDigits sqrt();
    BufferDigits percent();
    BufferDigits operator+(BufferDigits other);
    BufferDigits operator-(BufferDigits other);
    BufferDigits operator/(BufferDigits other);
    BufferDigits operator*(BufferDigits other);
    static BufferDigits calc(BufferDigits one, BufferDigits two, Operator op);

};

class CPULucio: public Cpu{
  private:
    Display* display;
    bool on = false;

    bool treatPercentageEntry(Operator*);
    bool treatSquareRootEntry(Operator*);

  protected:

    virtual void clear();
    virtual void clearMemory();
    virtual void showBuffer(BufferDigits);
    void setError(bool);

    Operator* currentOperator = nullptr;
    BufferDigits op1;
    BufferDigits op2;
    BufferDigits mem;

  public:
    Display* getDisplay() override;
    void setDisplay(Display*) override;
    
    void receiveDigit(Digit) override;
    void receiveOperator(Operator*) override;
    void receiveControl(Control) override;

};