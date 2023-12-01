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
  this->getKeyboard()->getCpu()->receiveDigit(this->digit);
}

KeyOperatorLucio::KeyOperatorLucio(Symbol symbol, Operator operator_) : KeyBase(symbol) {
  this->operator_ = operator_;
}

Operator KeyOperatorLucio::getOperator() { return this->operator_; }

void KeyOperatorLucio::press(){
  this->getKeyboard()->getCpu()->receiveOperator(this->operator_);
}

KeyControlLucio::KeyControlLucio(Symbol symbol, Control control) : KeyBase(symbol) {
  this->control = control;
}

Control KeyControlLucio::getControl() { return this->control; }

void KeyControlLucio::press(){
  this->getKeyboard()->getCpu()->receiveControl(this->control);
}
