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
    BufferDigits(long double value);

    std::vector<Digit> getDigits();
    int getDecimalPosition();

    void addDigit(Digit);
    void setDecimalSeparator();
    bool getDecimalSeparator();
    void setNegative(bool);
    bool getNegative();
    void clear();
    float getValue();
	  void setValue(long double& value);
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
    bool error = false;
    bool on = false;
    bool memoryRead = false;
    bool treatPercentageEntry(Operator*);
    bool treatSquareRootEntry(Operator*);
    BufferDigits* currentBuffer;

  protected:

    virtual void clear();
    virtual void memoryReadClear();
    virtual void showBuffer(BufferDigits);
    void setError(bool);
    BufferDigits* getCurrentBuffer();
    void setCurrentBuffer(BufferDigits*);
    
    Operator* currentOperator = nullptr;
    BufferDigits op1;
    BufferDigits op2;
    BufferDigits mem;


  public:
    Display* getDisplay() override;
    void setDisplay(Display*) override;
    void setMRC(bool);
    bool getMRC();
    void receiveDigit(Digit) override;
    void receiveOperator(Operator*) override;
    void receiveControl(Control) override;



};