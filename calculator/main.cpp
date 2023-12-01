#include <iostream>
#include <conio.h>
#include "components/Calculator.hpp"
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std; 

int main(int argc, char** argv){
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif

    char tecla;

    do{

        tecla = _getch();

        std::cout << "Tecla pressionada: " << tecla << std::endl;
        
    }while(tecla != 'q');
    
    return 0;
}