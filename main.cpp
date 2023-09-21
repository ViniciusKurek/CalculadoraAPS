#include <iostream>
#include "Calculator Components\Calculator.hpp"
#include "Calculator Components\CPU.hpp"
#include "Calculator Components\Display.hpp"
#include "Calculator Components\Key.hpp"
#include "Calculator Components\Keyboard.hpp"

using namespace std; 

// Abstrair: Enxergar as partes de um sistema.
// Encapsulamento: Esconder coisas dentro de uma capsula (a classe).

int main(int argc, char** argv){

    CPU cpu1;
    Keyboard keyboard1;


    keyboard1.setCPU(&cpu1);
    Calculator c1;
    


    return 0;
}