#include "src/Display/Console.h"
#include <iostream>

int main(){
    Console::init();

    try{
        Console::show();
    }catch(const char* error){
        Console::show(error);
    }
}