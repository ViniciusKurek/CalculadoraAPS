#include "DisplayNat.hpp"

void DisplayNat::showDigits(){
  Console::setColor(Color::BG_Blue);  
  Console::setColor(Color::FG_White);  
  Console::clearScreen();

  for(int i= 0; i < this->digitsCount; i++){ 
    switch(this->digits[i]){
      case ZERO: this->showDigit(0, 1, i); break;
      case ONE: this->showDigit(1, 1, i); break;
      case TWO: this->showDigit(2, 1, i); break;
     default:
       this->showDigit(10, 1, i); break;
   }
  }
}

// void DisplayNat::add(Digit digit){
//   this->digits[this->digitsCount++] = digit;
//   this->showDigits();
// }