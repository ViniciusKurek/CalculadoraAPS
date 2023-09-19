#include <iostream>
#include "Calculator.hpp"
#include "CPU.hpp"
#include "Display.hpp"
#include "Key.hpp"
#include "Keyboard.hpp"

using namespace std; 

// Abstrair: Enxergar as partes de um sistema.
// Encapsulamento: Esconder coisas dentro de uma capsula (a classe).

int main(int argc, char** argv){
    Calculator c1;
    c1.keyboard1.getKey();


    return 0;
}