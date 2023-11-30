#include <iostream>
#include "components/DisplayNat.hpp"
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std; 

int main(int argc, char** argv){
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif

    DisplayNat* display = new DisplayNat();

    display->add(Digit::NINE);
    display->setDecimalSeparator();
    display->setNegative(true);
    display->setMemory(true);
    display->show();

    return 0;
}