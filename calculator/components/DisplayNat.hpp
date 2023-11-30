#pragma once

#include "CalculatorInterfaces.hpp"

class DisplayNat: public Display{
  protected: 
    Digit digits[8];
    unsigned char digitsCount = 0;
    unsigned char decimalSeparatorPosition = 0;

    bool error = false;
    bool memory = false;
    bool negative = false;

    void initShow();
    virtual void evaluateDigit(Digit, int);
    virtual void showControls(int row, int col);
    virtual void showDigit(int digitIndex, int row, int col);

  public: // Métodos herdados da interface Display
    void add(Digit);
    void setDecimalSeparator();
    void clear();
    void show();
    void setError(bool);
    void setMemory(bool);
    void setNegative(bool);
};
