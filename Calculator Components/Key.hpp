#pragma once
#include <iostream>
#include "Keyboard.hpp"


using namespace std; 

class Key{ // Responsible for the input.
    Keyboard* keyboard1;
    Symbol symbol;


    public:
        Key(Symbol);

        void Press();
        void setKeyboard(Keyboard*);
        Keyboard* getKeyboard();
};


class KeyDigit: public Key{
    Digit digit;

    public:
        KeyDigit(Symbol, Digit);
        Digit getDigit();
};

class KeyOperator: public Key{
    Operator operation;

    public:
        KeyOperator(Symbol, Operator);
        Operator getOperator();

};

class KeyControl: public Key{
    Control controller;

    public:
        KeyControl(Symbol, Control);
        Control getControl();
};