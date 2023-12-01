#pragma once
#include <iostream>
#include "CalculatorInterfaces.hpp"

using namespace std; 

class CalculatorNat : public Calculator{ // Assembler class.
    Display* display;
    Cpu* cpu;
    Keyboard* keyboard;
    
public:
    void setDisplay(Display* ) override;
    Display* getDisplay() override;
    void setCpu(Cpu* ) override;
    Cpu* getCpu() override;
    void setKeyboard(Keyboard* ) override;
    Keyboard* getKeyboard() override;

};