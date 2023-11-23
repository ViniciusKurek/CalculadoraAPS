#pragma once

enum Digit{ ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

enum Operator{ SUM, SUBTRACTION, DIVISION, MULTIPLICATION, PERCENTAGE, SQUARE_ROOT};

enum Control{ ON, OFF, CLEAR_ERROR, MEMORY_READ_CLEAR, MEMORY_SUM, MEMORY_SUBTRACTION, EQUAL, DECIMAL_SEPARATOR};

class Display{
  public:
    static const char MAX_DIGITS = 8; 

    virtual void add(Digit) = 0;
    virtual void setDecimalSeparator() = 0;
    virtual void clear() = 0;
    virtual void setError(bool) = 0;
    virtual void setMemory(bool) = 0;
    virtual void setNegative(bool) = 0;
};

typedef const char* Symbol;

class Cpu{
  public:
    virtual Display* getDisplay() = 0;
    virtual void setDisplay(Display*) = 0;

    virtual void receiveDigit(Digit) = 0;
    virtual void receiveOperator(Operator) = 0;
    virtual void receiveControl(Control) = 0;
};

class Keyboard;

class Key{
  public:
    virtual void press() = 0;

    virtual Symbol getSymbol() = 0;

    virtual void setKeyboard(Keyboard*) = 0;
    virtual Keyboard* getKeyboard() = 0;
};

class KeyDigit: public virtual Key{
  public:
    virtual Digit getDigit() = 0;
};

class KeyOperator: public virtual Key{
  public:
    virtual Operator getOperator() = 0;
};

class KeyControl: public virtual Key{
  public:
    virtual Control getControl() = 0;
};


class Keyboard{
  public:
    virtual void addKey(Key*) = 0;
    virtual void removeKey(Key*) = 0;
    virtual Key* findKey(Symbol) = 0;
    virtual void setCpu(Cpu*) = 0;
    virtual Cpu* getCpu() = 0;
};

class Calculator{
  public:
    virtual void setDisplay(Display* ) = 0;
    virtual Display* getDisplay() = 0;
    virtual void setCpu(Cpu* ) = 0;
    virtual Cpu* getCpu() = 0;
    virtual void setKeyboard(Keyboard* ) = 0;
    virtual Keyboard* getKeyboard() = 0;
};