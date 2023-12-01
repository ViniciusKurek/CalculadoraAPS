#include "KeyLucio.hpp"

KeyBase::KeyBase(Symbol symbol) { this->symbol = symbol; }

Symbol KeyBase::getSymbol() { return this->symbol; }

void KeyBase::setKeyboard(Keyboard *keyboard) { this->keyboard = keyboard; }
Keyboard *KeyBase::getKeyboard() { return this->keyboard; }

KeyDigitLucio::KeyDigitLucio(Symbol symbol, Digit digit) : KeyBase(symbol) {
  this->digit = digit;
}

Digit KeyDigitLucio::getDigit() { return this->digit; }

void KeyDigitLucio::press(){
  if(this->getKeyboard() == nullptr) throw "Key is not connected to a keyboard!";
  if(this->getKeyboard()->getCpu() == nullptr) throw "Keyboard is not connected to a CPU!";
  this->getKeyboard()->getCpu()->receiveDigit(this->digit);
}

KeyOperatorLucio::KeyOperatorLucio(Symbol symbol, Operator operator_) : KeyBase(symbol) {
  this->operator_ = operator_;
}

Operator KeyOperatorLucio::getOperator() { return this->operator_; }

void KeyOperatorLucio::press(){
  if(this->getKeyboard() == nullptr) throw "Key is not connected to a keyboard!";
  if(this->getKeyboard()->getCpu() == nullptr) throw "Keyboard is not connected to a CPU!";
  this->getKeyboard()->getCpu()->receiveOperator(&this->operator_);
}

KeyControlLucio::KeyControlLucio(Symbol symbol, Control control) : KeyBase(symbol) {
  this->control = control;
}

Control KeyControlLucio::getControl() { return this->control; }

void KeyControlLucio::press(){
  if(this->getKeyboard() == nullptr) throw "Key is not connected to a keyboard!";
  if(this->getKeyboard()->getCpu() == nullptr) throw "Keyboard is not connected to a CPU!";
  this->getKeyboard()->getCpu()->receiveControl(this->control);
}
