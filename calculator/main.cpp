#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std; 

int main(int argc, char** argv){
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif
    
    return 0;
}