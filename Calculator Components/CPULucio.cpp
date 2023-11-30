#include "CPULucio.hpp"
#include <iostream>

Display *CpuLucio::getDisplay() { return this->display; }
void CpuLucio::setDisplay(Display *display) { this->display = display; }

void CpuLucio::receiveDigit(Digit digit) {
  if(this->display!=nullptr);
    /* TODO */
    if(this->currentOperator == nullptr)
      this->op1.addDigit(digit);
    else
      this->op2.addDigit(digit);

}
void CpuLucio::receiveOperator(Operator* newOperator) { /* TODO */
  this->currentOperator = newOperator;
}
void CpuLucio::receiveControl(Control control) { /* TODO */
  switch (control)
  {
  case DECIMAL_SEPARATOR:
    if(this->currentOperator == nullptr)
      this->op1.setDecimalSeparator();
    else
      this->op2.setDecimalSeparator();
    break;
  
  default:
    break;
  }

}

int BufferDigits::digitToInt(Digit digit){
  switch (digit)
  {
    case ZERO: return 0;
    case ONE: return 1;
    case TWO: return 2;
    case THREE: return 3;
    case FOUR: return 4;
    case FIVE: return 5;
    case SIX: return 6;
    case SEVEN: return 7;
    case EIGHT: return 8;
    case NINE: return 9;
    default: return 0;
  }
}

void BufferDigits::addDigit(Digit digit){
  this->digits.push_back(digit);
}

void BufferDigits::setDecimalSeparator(){
  this->decimalPosition = this->digits.size();
}

float BufferDigits::getValue(){
  std::string saida;

  for(int i = 0; i < this->digits.size(); i++){ // 24.3 0.5
    if(i == this->decimalPosition) saida += ".";
    saida += std::to_string(this->digitToInt(this->digits[i]));
  }

  return std::stof(saida);
}