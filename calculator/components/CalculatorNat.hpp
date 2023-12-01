#pragma once
#include <iostream>
#include "CalculatorInterfaces.hpp"
#include "CPULucio.hpp"
#include "DisplayNat.hpp"
#include "KeyboardLucio.hpp"

using namespace std; 

class CalculatorNat : public Calculator{ // Assembler class.
    DisplayNat display;
    CPULucio cpu;
    KeyboardLucio keyboard;
    
    public:



};