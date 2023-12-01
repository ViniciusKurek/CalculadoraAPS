#include "CPULucio.hpp"
#include <iostream>
#include <cmath>

BufferDigits::BufferDigits(){
  this->decimalPosition = 0;
  this->decimalLocked = false;
}

BufferDigits::BufferDigits(float value){
  this->setValue(value);
}

std::vector<Digit> BufferDigits::getDigits(){
  return this->digits;
}

int BufferDigits::getDecimalPosition(){
  return this->decimalPosition;
}

void CPULucio::clear(){
  this->op1.clear();
  this->op2.clear();
  this->result.clear();
  this->currentOperator = nullptr;
}

void CPULucio::clearMemory(){
  this->mem.clear();
}

void CPULucio::showBuffer(BufferDigits buffer){
  if(this->getDisplay() != nullptr){
    this->getDisplay()->clear();
    auto digits = buffer.getDigits();

    for(int i = 0; i < digits.size(); i++){
      if(i != 0 && i == buffer.getDecimalPosition())
        this->getDisplay()->setDecimalSeparator();

      this->getDisplay()->add(digits[i]);
    }

  }
}

Display *CPULucio::getDisplay() { return this->display; }
void CPULucio::setDisplay(Display *display) { this->display = display; }

void CPULucio::receiveDigit(Digit digit) {
  if(!this->on) return;
  if(this->display == nullptr) throw "Display is not connected to CPU!";

  if(this->currentOperator == nullptr){
    this->op1.addDigit(digit);
    this->showBuffer(this->op1);
  }
  else{
    this->op2.addDigit(digit);
    this->showBuffer(this->op2);
  }

}
void CPULucio::receiveOperator(Operator* newOperator) {
  if(!this->on) return;
  if(this->op1.isEmpty()) return;
  this->currentOperator = newOperator;
}
void CPULucio::receiveControl(Control control) {
  if(control == ON){
    this->on = true;
    this->showBuffer(this->op1);
  }
  
  if(!this->on) return;

  switch (control){

    case OFF:
      this->clear();
      this->clearMemory();
      this->on = false;
      break;

    case DECIMAL_SEPARATOR:
      if(this->currentOperator == nullptr)
        this->op1.setDecimalSeparator();
      else
        this->op2.setDecimalSeparator();
      break;

    case CLEAR_ERROR: 
      this->clear();
      this->showBuffer(this->op1);
      break;

    case MEMORY_READ_CLEAR:
      this->clearMemory();
      break;

    case EQUAL:
      if(this->currentOperator != nullptr){
        if(this->op2.isEmpty()) this->op2 = this->op1; // X + ? = ?

        if(this->result.isEmpty()) {
          this->result = BufferDigits::calc(this->op1, this->op2, *this->currentOperator); // X + X = ?
        }
        else{
          this->result = BufferDigits::calc(this->op2, this->result, *this->currentOperator); // X + X = Y
        }

        this->showBuffer(this->result);
      }
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
  if(this->digits.size() < Display::MAX_DIGITS) this->digits.push_back(digit);
  if(!this->decimalLocked) this->decimalPosition++;
}

void BufferDigits::setDecimalSeparator(){
  this->decimalLocked = true;
}

float BufferDigits::getValue(){
  float saida = 0;
  
  for(int i = 0; i < this->digits.size(); i++){
      saida += this->digits[i] * pow(10, (this->digits.size() -1 ) - i); 
  }
  
  saida = saida / pow(10, this->digits.size() - this->decimalPosition);

  return saida;
}

void BufferDigits::clear(){
  this->digits.clear();
  this->decimalPosition = 0;
  this->decimalLocked = false;
}


void BufferDigits::setValue(float value){
  this->clear();

  int valueInt = value;
  int count = 0;
  if(valueInt == 0) count++;
  
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
    if(i == count) this->setDecimalSeparator();
		this->addDigit(this->intToDigit(digit));
	}
}

void BufferDigits::print(){
  std::cout << "Digitos: ";
  for(int i = 0; i < this->digits.size(); i++){
    std::cout << BufferDigits::digitToInt(this->digits[i]) << " ";
  }
  std::cout << std::endl;

  std::cout << "Posicao do ponto: " << this->decimalPosition << std::endl;
}

bool BufferDigits::isEmpty(){
  if(this->digits.size() == 0) return true;
  return false;
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

BufferDigits BufferDigits::calc(BufferDigits one, BufferDigits two, Operator op){
  switch(op)
  {
    case SUM: return one + two;
    case SUBTRACTION: return one - two;
    case MULTIPLICATION: return one * two;
    case DIVISION: return one / two;
  }
  return BufferDigits();
}
