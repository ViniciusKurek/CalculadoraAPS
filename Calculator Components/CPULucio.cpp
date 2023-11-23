#include "CPULucio.hpp"

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

void BufferDigits::addDigit(Digit digit){
  this->digits.push_back(digit);
}

void BufferDigits::setDecimalSeparator(){
  this->decimalPosition = this->digits.size();
}