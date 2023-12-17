#include <iostream>
#ifdef _WIN32
    #include <windows.h>
#endif

#include "src/Manager/DAOManager.h"

int main(){
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif

    DAOManager::init(true);

    return 0;
}