#include "utils.hpp"

class Display{
    
protected:
   Digit digits[8];
   unsigned char digitsCount = 0;
   unsigned char decimalSeparatorPosition = 0;

   virtual void showDigits();
   virtual void showDigit(int digitIndex, int row, int col);

  public:
  virtual void add(Digit);
  virtual  void setDecimalSeparator();
  virtual  void clear();
  virtual  void setError(bool);
  virtual  void setMemory(bool);
  virtual  void setNegative(bool);
};

//#endif