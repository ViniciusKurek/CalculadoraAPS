#include "Display.hpp"
#include <iostream>
using namespace std; 

void Display::add(Digit digit){
    switch(digit){
        case ZERO: cout << " 0000\n0    0\n0    0\n0    0\n0    0\n0    0\n0    0\n 0000  "; break;
        case ONE: cout << "    \n     1\n     1\n     1\n     1\n     1\n     1\n  "; break;
        case TWO: cout << " 2222\n     2\n     2\n     2\n 2222\n2\n2\n2\n 2222  "; break;
        case THREE: cout << " 3333\n     3\n     3\n     3\n 3333\n     3\n     3\n     3\n 3333  "; break;
        case FOUR: cout << "    \n4    4\n4    4\n4    4\n 4444\n     4\n     4\n     4  "; break;
        case FIVE: cout << " 5555\n5\n5\n5\n 5555\n     5\n     5\n     5\n 5555  "; break;
        case SIX: cout << " 6666\n6\n6\n6\n 6666\n6     6\n6     6\n6     6\n 6666  "; break;
        case SEVEN: cout << " 7777\n     7\n     7\n     7\n     7\n     7\n     7\n  "; break;
        case EIGHT: cout << " 8888\n8    8\n8    8\n8    8\n 8888\n8    8\n8    8\n8    8\n 8888  "; break;
        case NINE: cout << " 9999\n4    9\n4    9\n4    9\n 9999\n     9\n     9\n     9  "; break;
        default:
            cout << "ERROR";
    }
    
}

void Display::setDecimalSeparator(){
    cout << "\n\n\n\n\n\n\n.\n";
}

void Display::clear(){
    cout << "\n\n\n\n\n\n\n\n\n\n";
}

