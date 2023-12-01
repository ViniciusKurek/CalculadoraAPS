#include "CPULucio.hpp"
#include <iostream>
#include <cmath>

BufferDigits::BufferDigits(){
  this->decimalPosition = 0;
}

BufferDigits::BufferDigits(float value){
  this->setValue(value);
}

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

  case CLEAR_ERROR: 
    this->op1.clear();
    this->op2.clear();
    this->result.clear();
    this->currentOperator = nullptr;
    break;

  case MEMORY_READ_CLEAR:
    /* TODO */
    break;

  
  default:
    break;
  }

}

int BufferDigits::digitToInt(Digit digit)
{
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

Digit BufferDigits::intToDigit(int integer){
  switch (integer)
  {
    case 0: return ZERO;
    case 1: return ONE;
    case 2: return TWO;
    case 3: return THREE;
    case 4: return FOUR;
    case 5: return FIVE;
    case 6: return SIX;
    case 7: return SEVEN;
    case 8: return EIGHT;
    case 9: return NINE;
    default: return INVALID;
  }
}



void BufferDigits::addDigit(Digit digit){
  this->digits.push_back(digit);
}

void BufferDigits::setDecimalSeparator(){
  this->decimalPosition = this->digits.size();
}

float BufferDigits::getValue(){
  float saida = 0;
  
  for(int i = 0; i < this->digits.size(); i++){
      saida += this->digits[i] * pow(10, (this->digits.size() -1 ) - i); // 15.435
  }
  
  saida = saida / pow(10, (this->digits.size()) - this->decimalPosition);

  return saida;
}

void BufferDigits::clear(){
  this->digits.clear();
  this->decimalPosition = 0;
}


void BufferDigits::setValue(float value){
  this->clear();

  int valueInt = value;
  int count = 0;
  
  while(valueInt > 0){
    count++;
    valueInt = valueInt/10;
  }

  std::string temp = std::to_string(value);
  std::string sValue;

  for(int i = 0; i < temp.size(); i++){
    if(temp[i] != '.') sValue.push_back(temp[i]);
  }

  for(int i = sValue.size() - 1; i >= count; i--){
		
		if(sValue[i] != '0')
			break;

		sValue.pop_back();		
	}

  for(int i = 0; i < sValue.size(); i++){
		char c = sValue[i];
		int digit = c - '0';
		this->addDigit(this->intToDigit(digit));
	}

  this->decimalPosition = count;
}

void BufferDigits::print(){
  std::cout << "Digitos: ";
  for(int i = 0; i < this->digits.size(); i++){
    std::cout << BufferDigits::digitToInt(this->digits[i]) << " ";
  }
  std::cout << std::endl;

  std::cout << "Posicao do ponto: " << this->decimalPosition << std::endl;
}

BufferDigits BufferDigits::percent(){
  return BufferDigits(this->getValue() / 100);
}

BufferDigits BufferDigits::sqrt(){
  return BufferDigits(std::sqrt(this->getValue()));
}

BufferDigits BufferDigits::operator+(BufferDigits other){
 return BufferDigits(this->getValue() + other.getValue());
}

BufferDigits BufferDigits::operator-(BufferDigits other){
 return BufferDigits(this->getValue() - other.getValue());
}

BufferDigits BufferDigits::operator/(BufferDigits other){
 return BufferDigits(this->getValue() / other.getValue());
}

BufferDigits BufferDigits::operator*(BufferDigits other){
  return BufferDigits(this->getValue() * other.getValue());
}
