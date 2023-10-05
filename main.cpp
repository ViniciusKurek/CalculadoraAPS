#include <iostream>
// #include "Calculator Components\Calculator.hpp"
// #include "Calculator Components\CPU.hpp"
#include "Calculator Components\Display.hpp"
// #include "Calculator Components\Key.hpp"
// #include "Calculator Components\Keyboard.hpp"
#include "Calculator Components\Console.hpp"

using namespace std; 

// Abstrair: Enxergar as partes de um sistema.
// Encapsulamento: Esconder coisas dentro de uma capsula (a classe).

int main(int argc, char** argv){
    Console::init(10, 5);
    Display display1;

    // display1.add(TWO);
    // display1.add(FOUR);
    // display1.add(THREE);
    // display1.add(FOUR);
    // display1.setDecimalSeparator()c;
    // display1.clear();

    display1.add(ONE);
    display1.add(TWO);
    display1.add(THREE);
    display1.add(FOUR);
    display1.setDecimalSeparator();
    display1.add(ZERO);
    display1.add(FIVE);
    display1.add(SIX);
    display1.add(SEVEN);
    display1.add(EIGHT);

    // CPU cpu1;
    // Keyboard keyboard1;


    // keyboard1.setCPU(&cpu1);
    // Calculator calculator1;

    // calculator1.getKeyboard().getKey("1").press();
    // calculator1.getKeyboard().getKey("+").press();
    // calculator1.getKeyboard().getKey("1").press();
    // calculator1.getKeyboard().getKey("=").press();
    Console::setCursor(0, 20);
    

    return 0;
}