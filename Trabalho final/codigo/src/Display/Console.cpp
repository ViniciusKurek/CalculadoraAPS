#include "Console.h"
#include "Modules/MainModule.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

Module* Console::mainModule = nullptr;
Module* Console::currentModule = nullptr;

void Console::clear(){
    std::cout << "\033[2J\033[1;1H";
}

void Console::showModuleName(){
    if(Console::currentModule == nullptr) throw "Módulo atual não definido";
    std::cout << Console::currentModule->getName() << std::endl << std::endl;
}

void Console::showModuleContent(){
    if(Console::currentModule == nullptr) throw "Módulo atual não definido";

    for(std::string line : Console::currentModule->getContent())
        std::cout << line << std::endl;
    std::cout << std::endl;
}



void Console::showModuleNavigation(){
    if(Console::currentModule == nullptr) throw "Módulo atual não definido";
    std::cout << "Exibindo a navegação do módulo atual" << std::endl;
}

void Console::showError(const char* error){
    std::cout << "[ERRO] " << error << std::endl;
}

void Console::reset(){
    Console::currentModule = Console::mainModule;
    Console::show();
}

void Console::receiveKey(char &&key){

}

void Console::show(){
    Console::clear();
    Console::showModuleName();
    Console::showModuleContent();
    Console::showModuleNavigation();
}

void Console::show(const char* error){
    if(Console::currentModule != nullptr)
        Console::show();
    Console::showError(error);
}

void Console::init(){
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif

    Console::mainModule = new MainModule("Menu Principal");
}