#include "CalculatorNat.hpp"

void CalculatorNat::setDisplay(Display* display){ this->display = display; }
Display* CalculatorNat::getDisplay(){ return this->display; }
void CalculatorNat::setCpu(Cpu* cpu){ this->cpu = cpu; }
Cpu* CalculatorNat::getCpu(){ return this->cpu; }
void CalculatorNat::setKeyboard(Keyboard* keyboard){ this->keyboard = keyboard; }
Keyboard* CalculatorNat::getKeyboard(){ return this->keyboard; }