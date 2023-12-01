#pragma once

#include "CalculatorInterfaces.hpp"

class KeyBase: public virtual Key{
  Keyboard* keyboard;
  Symbol symbol;
  public:
    KeyBase(Symbol);

    Symbol getSymbol();

    void setKeyboard(Keyboard*);
    Keyboard* getKeyboard();
};

class KeyDigitLucio: public KeyBase, public KeyDigit{
  Digit digit;

  public:
    KeyDigitLucio(Symbol, Digit);

    Digit getDigit();

    void press();
};


class KeyOperatorLucio: public KeyBase, public KeyOperator{
  Operator operator_;

  public:
    KeyOperatorLucio(Symbol, Operator);

    Operator getOperator();

    void press();
};


class KeyControlLucio: public KeyBase, public KeyControl{
  Control control;

  public:
    KeyControlLucio(Symbol, Control);

    Control getControl();

    void press();
};