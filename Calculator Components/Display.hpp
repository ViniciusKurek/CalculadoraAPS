#pragma once
#include "utils.hpp" 

using namespace std; 

class Display{ // Shows the output.
    Digit digits[8];
    char digitCount = 0;

    void showDigits();

    public:
    void add(Digit);
    void setDecimalSeparator();
    void clear();

    void setMemory(bool);
    void setNegative(bool);
    void setError(bool);

};
