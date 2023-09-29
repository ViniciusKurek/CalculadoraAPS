#include <iostream>
// #include "Calculator Components\Calculator.hpp"
// #include "Calculator Components\CPU.hpp"
#include "Calculator Components\Display.hpp"
// #include "Calculator Components\Key.hpp"
// #include "Calculator Components\Keyboard.hpp"

using namespace std; 

// Abstrair: Enxergar as partes de um sistema.
// Encapsulamento: Esconder coisas dentro de uma capsula (a classe).

int main(int argc, char** argv){
    Display display1;
    display1.add(ZERO);
    display1.clear();
    display1.add(ZERO);

    // CPU cpu1;
    // Keyboard keyboard1;


    // keyboard1.setCPU(&cpu1);
    // Calculator calculator1;

    // calculator1.getKeyboard().getKey("1").press();
    // calculator1.getKeyboard().getKey("+").press();
    // calculator1.getKeyboard().getKey("1").press();
    // calculator1.getKeyboard().getKey("=").press();
    


    return 0;
}