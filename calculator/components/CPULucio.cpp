#include "CPULucio.hpp"
#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>

BufferDigits::BufferDigits(){
  this->decimalPosition = 0;
  this->decimalLocked = false;
}

BufferDigits::BufferDigits(long double value){
  this->setValue(value);
}

std::vector<Digit> BufferDigits::getDigits(){
  return this->digits;
}

int BufferDigits::getDecimalPosition(){
  return this->decimalPosition;
}

void CPULucio::clear(){
  if(this->getDisplay() == nullptr) throw "Display is not connected to CPU!";

  this->op1.clear();
  this->op2.clear();
  this->getDisplay()->setError(false);
  this->getDisplay()->setNegative(false);
  this->error = false;
  this->currentOperator = nullptr;
}

void CPULucio::setMRC(bool condition){
  this->memoryRead = condition;
}

bool CPULucio::getMRC(){
  return this->memoryRead;
}

void CPULucio::memoryReadClear(){
  BufferDigits *old = this->getCurrentBuffer();
  if(this->getMRC() == false){
    *this->getCurrentBuffer() = this->mem;
    this->setMRC(true);
    this->showBuffer(*this->getCurrentBuffer());
    return;
  }
  else 
    this->getCurrentBuffer()->clear();
    this->mem.clear();
    this->setMRC(false);
    this->getDisplay()->setMemory(false);
    this->getDisplay()->setNegative(false);
    this->showBuffer(*old);
    return;

}

BufferDigits* CPULucio::getCurrentBuffer(){
  return this->currentBuffer;
}

void CPULucio::setCurrentBuffer(BufferDigits *buffer){
  this->currentBuffer = buffer;
}


void CPULucio::showBuffer(BufferDigits buffer){
  if(this->getDisplay() == nullptr) throw "Display is not connected to CPU!";

  this->getDisplay()->clear();

  auto digits = buffer.getDigits();


  this->getDisplay()->setMemory(!this->mem.isEmpty());
  this->getDisplay()->setNegative(buffer.getNegative());

  for(int i = 0; i < digits.size(); i++){
    if(i != 0 && i == buffer.getDecimalPosition())
      this->getDisplay()->setDecimalSeparator();

    this->getDisplay()->add(digits[i]);
  }
}

void CPULucio::setError(bool error){
  if(this->getDisplay() == nullptr) throw "Display is not connected to CPU!";
  this->error = error;
  this->getDisplay()->setError(error);
}

Display *CPULucio::getDisplay() { return this->display; }
void CPULucio::setDisplay(Display *display) { this->display = display; }

void CPULucio::receiveDigit(Digit digit) {
  if(!this->on) return;
  if(this->error) return;
  if(this->display == nullptr) throw "Display is not connected to CPU!";

  if(this->getMRC()) this->getCurrentBuffer()->clear();
  this->setMRC(false);

  if((this->getCurrentBuffer() == &this->op1 && !this->op2.isEmpty()) && this->currentOperator != nullptr){
    this->op1.clear();
    this->op2.clear();
    this->currentOperator = nullptr;
  }

  if(this->currentOperator != nullptr && this->getCurrentBuffer() != &this->op2) this->op2.clear();
  
  if(this->currentOperator == nullptr) this->setCurrentBuffer(&this->op1);
  else this->setCurrentBuffer(&this->op2);

  if(this->getCurrentBuffer()->isEmpty()){
    if(this->getCurrentBuffer()->getDecimalSeparator())
      this->getCurrentBuffer()->addDigit(digit);
    else if(digit != ZERO)
      this->getCurrentBuffer()->addDigit(digit);
  }else{
    if(this->getCurrentBuffer()->getDigits().size() < this->getDisplay()->MAX_DIGITS){
      this->getCurrentBuffer()->addDigit(digit);
    }else
      return;
  }

  this->showBuffer(*this->getCurrentBuffer());
}

bool CPULucio::treatPercentageEntry(Operator* newOperator){
  if(*newOperator == PERCENTAGE){
    if(this->op1.isEmpty()) return true;
    if(this->currentOperator == nullptr){
      this->op1.clear();
      this->showBuffer(this->op1);
    }
    else{
      // TEM NO BUFFER 1, TEM OPERADOR
      if(*this->currentOperator == MULTIPLICATION || *this->currentOperator == DIVISION){
        if(this->op2.isEmpty()) this->op2 = this->op1.percent();
        else this->op2 = this->op2.percent();
      }else{
        if(this->op2.isEmpty()) this->op2 = this->op1;
        this->op2 = (this->op1.percent()) * this->op2;
      }

      this->op2 = BufferDigits::calc(this->op1, this->op2, *this->currentOperator);
      this->setCurrentBuffer(&this->op2);
      this->showBuffer(*this->getCurrentBuffer());
    }
    return true;
  }

  return false;
}

bool CPULucio::treatSquareRootEntry(Operator* newOperator){
  if(*newOperator == SQUARE_ROOT){

    // TEM NO BUFFER 1, NÃO TEM OPERADOR, NÃO TEM NO BUFFER 2
    if(!this->op1.isEmpty() && this->currentOperator == nullptr){
      
      if(this->op1.getValue() < 0){
        this->setError(true);
        this->showBuffer(this->op1);
        return true;
      }

      this->op1 = this->op1.sqrt();
      this->showBuffer(this->op1);
      return true;
    }

    // TEM NO BUFFER 1, TEM OPERADOR, NÃO TEM NO BUFFER 2
    if(this->op2.isEmpty() && this->currentOperator != nullptr){

      if(this->op1.getValue() < 0){
        this->setError(true);
        this->showBuffer(this->op1);
        return true;
      }

      this->op2 = this->op1.sqrt();
      this->showBuffer(this->op2);
      return true;
    }

    // TEM NO BUFFER 1, TEM OPERADOR, TEM NO BUFFER 2
    if(!this->op2.isEmpty()){

      if(this->op1.getValue() < 0){
        this->setError(true);
        this->showBuffer(this->op1);
        return true;
      }

      this->op2 = this->op2.sqrt();
      this->showBuffer(this->op2);
      return true;
    }

    return true;
  }
  return false;
}

void CPULucio::receiveOperator(Operator* newOperator) {
  if(!this->on) return;
  if(this->error) return;

  this->setMRC(false);

  // TRATANDO CASO A OPERAÇÃO SEJA PORCENTAGEM
  if(this->treatPercentageEntry(newOperator)) return;

  // TRATANDO CASO A OPERAÇÃO SEJA RADICIAÇÃO
  if(this->treatSquareRootEntry(newOperator)) return;
  
  if(this->op1.isEmpty()){
    if(this->getCurrentBuffer()->isEmpty() == false){
      this->op1 = *this->getCurrentBuffer();
    }
    else
      this->op1.setZero();
    this->currentOperator = newOperator;
    this->showBuffer(this->op1);

  }else {
    if(this->op2.isEmpty()) this->currentOperator = newOperator;
    else if (this->getCurrentBuffer() != &this->op1){
      this->op1 = BufferDigits::calc(this->op1, this->op2, *this->currentOperator);
      this->currentOperator = newOperator;
      this->op2.clear();
      this->showBuffer(this->op1);
    }else{
      this->currentOperator = newOperator;
      this->op2.clear();
    }
  }

}

void CPULucio::receiveControl(Control control) {
  if(control == Control::CLEAR_ERROR){
    this->setMRC(false);
    this->clear();
    this->setCurrentBuffer(&this->op1);
    this->showBuffer(*this->getCurrentBuffer());
    this->error = false;
    return;
  }

  if(control == ON){
    this->on = true;
    this->setCurrentBuffer(&this->op1);
    this->showBuffer(*this->getCurrentBuffer());
    return;
  }
  
  if(!this->on) return;
  if(this->error) return;

  if((control != MEMORY_READ_CLEAR)) this->setMRC(false);

  BufferDigits *old = new BufferDigits;
  old->setZero();

  switch (control){

    case OFF:
      this->clear();
      // if(this->getMRC())
      //   this->memoryReadClear(this->mem);
      this->on = false;
      this->showBuffer(this->op1);
      break;

    case DECIMAL_SEPARATOR:
      if((!this->op1.isEmpty()) && (!this->op2.isEmpty())){
        this->op1.clear();
        this->showBuffer(this->op1);
      }
      
      if(this->currentOperator == nullptr){
        if(this->op1.isEmpty()) this->op1.addDigit(ZERO);
        this->op1.setDecimalSeparator();
        this->showBuffer(this->op1);

        }
      else{
        if(this->op2.isEmpty()) this->op2.addDigit(ZERO);
        this->op2.setDecimalSeparator();
        this->showBuffer(this->op2);
      }
      break;

    case CLEAR_ERROR: 
      this->clear();
      this->showBuffer(this->op1);
      break;

    case MEMORY_READ_CLEAR:
      this->memoryReadClear();
      break;

    case EQUAL:
      if(this->currentOperator != nullptr){
        if(this->op2.isEmpty()) this->op2 = this->op1; // X + ?
        
        // VERIFICANDO SE A DIVISÃO É POR ZERO
        if(*this->currentOperator == DIVISION && this->op2.getValue() == 0){
          this->setError(true);
          return;
        }   
        
        this->op1 = BufferDigits::calc(this->op1, this->op2, *this->currentOperator);
        if(this->op1.getDecimalPosition() >= 9) this->setError(true);
        this->setCurrentBuffer(&this->op1);
        this->showBuffer(*this->getCurrentBuffer());
      }
      break;

    case MEMORY_SUM:
      if(this->currentOperator != nullptr && this->getCurrentBuffer() == &this->op2){
        *old = BufferDigits::calc(this->op1, this->op2, *this->currentOperator);
        this->mem = BufferDigits::calc(this->mem, *old, SUM);
        this->currentOperator = nullptr;
        this->getDisplay()->setMemory(true);
        this->setCurrentBuffer(old);
        this->showBuffer(*this->getCurrentBuffer());
        this->op1.clear();
        this->op2.clear();
      }
      else{
        bool isEmpty = this->mem.isEmpty();
        BufferDigits *bckp = this->getCurrentBuffer();
        *old = *bckp;
        this->mem = BufferDigits::calc(this->mem, *old, SUM);
        this->setCurrentBuffer(&(*old));
        this->getDisplay()->setMemory(true);
        if(isEmpty)
          this->showBuffer(*this->getCurrentBuffer());
        if(bckp != &this->mem)
          bckp->clear();
      }

    break;

    case MEMORY_SUBTRACTION:
      if(this->currentOperator != nullptr && this->getCurrentBuffer() == &this->op2){
        *old = BufferDigits::calc(this->op1, this->op2, *this->currentOperator);
        this->mem = BufferDigits::calc(this->mem, *old, SUBTRACTION);
        this->currentOperator = nullptr;
        this->getDisplay()->setMemory(true);
        this->setCurrentBuffer(old);
        this->showBuffer(*this->getCurrentBuffer());
        this->op1.clear();
        this->op2.clear();
      }
      else{
        bool isEmpty = this->mem.isEmpty();
        BufferDigits *bckp = this->getCurrentBuffer();
        *old = *bckp;
        this->mem = BufferDigits::calc(this->mem, *old, SUBTRACTION);
        this->setCurrentBuffer(&(*old));
        this->getDisplay()->setMemory(true);
        if(isEmpty)
          this->showBuffer(*this->getCurrentBuffer());
        if(bckp != &this->mem)
          bckp->clear();
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

bool BufferDigits::getDecimalSeparator(){
  return this->decimalLocked;
}

void BufferDigits::setNegative(bool isNegative){
  this->isNegative = isNegative;
}

bool BufferDigits::getNegative(){
  return this->isNegative;
}

float BufferDigits::getValue(){
  float saida = 0;
  
  for(int i = 0; i < this->digits.size(); i++){
      saida += this->digits[i] * pow(10, (this->digits.size() -1 ) - i); 
  }
  
  saida = saida / pow(10, this->digits.size() - this->decimalPosition);

  if(this->isNegative) saida = saida * -1;

  
  return saida;
}

void BufferDigits::clear(){
  this->isNegative = false;
  this->digits.clear();
  this->decimalPosition = 0;
  this->decimalLocked = false;
}


void BufferDigits::setValue(long double& value){
  this->clear();
 
  int valueInt = std::trunc(value);

  int count = 0;
  if(valueInt == 0) count++;


  while(valueInt > 0){
    count++;
    valueInt = valueInt/10;
  }
  
  std::ostringstream stream;
  stream << std::fixed << std::setprecision(7) << abs(value);
  std::string temp = stream.str();
  std::string sValue;


  for(int i = 0; i < temp.size(); i++){
    if(temp[i] != '.') sValue.push_back(temp[i]);
  }

  for(int i = sValue.size() - 1; i >= count; i--){
    if(sValue[i] != '0')
      break;
    sValue.pop_back();		
  }
  
  if(sValue.size() >= 9)
    sValue = std::to_string(value).substr(0,9); 

  for(int i = 0; i < sValue.size(); i++){
    
		char c = sValue[i];
		int digit = c - '0';
    if(i == count) this->setDecimalSeparator();
		this->addDigit(this->intToDigit(digit));
	}

  if(value < 0){
    this->setNegative(true);
    this->decimalPosition++;
  }

}

void BufferDigits::print(){
  std::cout << "Negativo: " << this->isNegative << std::endl;
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

void BufferDigits::setZero(){
  this->clear();
  this->addDigit(ZERO);
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
  long double a = this->getValue() - other.getValue();

  if(a < 0){
    a *= -1;
    BufferDigits* bf = new BufferDigits(a);
    bf->setNegative(true);
    return *bf;
  }

 return BufferDigits(a);
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

