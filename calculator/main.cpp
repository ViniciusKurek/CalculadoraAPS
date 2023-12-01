

#include "components/CalculatorNat.hpp"
#include "components/DisplayNat.hpp"
#include "components/CPULucio.hpp"
#include "components/KeyboardLucio.hpp"
#include "components/KeyLucio.hpp"
#include <iostream>
#include <conio.h>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

int main(int argc, char** argv){
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif

    // MONTANDO A CALCULADORA
    CalculatorNat* calculator = new CalculatorNat();

    // COMPONENTES
    DisplayNat* display = new DisplayNat();
    CPULucio* cpu = new CPULucio();
    KeyboardLucio* keyboard = new KeyboardLucio();

    // TECLAS DE DÍGITOS
    KeyDigitLucio* key0 = new KeyDigitLucio("0", Digit::ZERO);
    KeyDigitLucio* key1 = new KeyDigitLucio("1", Digit::ONE);
    KeyDigitLucio* key2 = new KeyDigitLucio("2", Digit::TWO);
    KeyDigitLucio* key3 = new KeyDigitLucio("3", Digit::THREE);
    KeyDigitLucio* key4 = new KeyDigitLucio("4", Digit::FOUR);
    KeyDigitLucio* key5 = new KeyDigitLucio("5", Digit::FIVE);
    KeyDigitLucio* key6 = new KeyDigitLucio("6", Digit::SIX);
    KeyDigitLucio* key7 = new KeyDigitLucio("7", Digit::SEVEN);
    KeyDigitLucio* key8 = new KeyDigitLucio("8", Digit::EIGHT);
    KeyDigitLucio* key9 = new KeyDigitLucio("9", Digit::NINE);

    // TECLAS DE OPERAÇÕES
    KeyOperatorLucio* keyPlus = new KeyOperatorLucio("+", Operator::SUM);
    KeyOperatorLucio* keyMinus = new KeyOperatorLucio("-", Operator::SUBTRACTION);
    KeyOperatorLucio* keyTimes = new KeyOperatorLucio("*", Operator::MULTIPLICATION);
    KeyOperatorLucio* keyDivide = new KeyOperatorLucio("/", Operator::DIVISION);
    KeyOperatorLucio* keyPercentage = new KeyOperatorLucio("%", Operator::PERCENTAGE);
    KeyOperatorLucio* keySquareRoot = new KeyOperatorLucio("v", Operator::SQUARE_ROOT);

    // TECLAS DE CONTROLE
    KeyControlLucio* keyClear = new KeyControlLucio("c", Control::CLEAR_ERROR);
    KeyControlLucio* keyDecimalSeparator = new KeyControlLucio(",", Control::DECIMAL_SEPARATOR);
    KeyControlLucio* keyEquals = new KeyControlLucio("=", Control::EQUAL);
    KeyControlLucio* keyMemReadClear = new KeyControlLucio("x", Control::MEMORY_READ_CLEAR);
    KeyControlLucio* keyMemSub = new KeyControlLucio("[", Control::MEMORY_SUBTRACTION);
    KeyControlLucio* keyMemSum = new KeyControlLucio("]", Control::MEMORY_SUM);
    KeyControlLucio* keyOff = new KeyControlLucio("d", Control::OFF);
    KeyControlLucio* keyOn = new KeyControlLucio("l", Control::ON);

    // LIGANDO AS TECLAS NO TECLADO
    keyboard->addKey(key0);
    keyboard->addKey(key1);
    keyboard->addKey(key2);
    keyboard->addKey(key3);
    keyboard->addKey(key4);
    keyboard->addKey(key5);
    keyboard->addKey(key6);
    keyboard->addKey(key7);
    keyboard->addKey(key8);
    keyboard->addKey(key9);
    keyboard->addKey(keyPlus);
    keyboard->addKey(keyMinus);
    keyboard->addKey(keyTimes);
    keyboard->addKey(keyDivide);
    keyboard->addKey(keyPercentage);
    keyboard->addKey(keySquareRoot);
    keyboard->addKey(keyClear);
    keyboard->addKey(keyDecimalSeparator);
    keyboard->addKey(keyEquals);
    keyboard->addKey(keyMemReadClear);
    keyboard->addKey(keyMemSub);
    keyboard->addKey(keyMemSum);
    keyboard->addKey(keyOff);
    keyboard->addKey(keyOn);

    // CONECTANDO COMPONENTES
    calculator->setCpu(cpu);
    calculator->setDisplay(display);
    calculator->setKeyboard(keyboard);

    char tecla;

    do{
        tecla = getch();

        char* symbol = &tecla;

        try{
            auto key = calculator->getKeyboard()->findKey(symbol);
            std::cout << "Key encontrada" << std::endl;
        }catch(const char* msg){
            cout << msg << endl;
        }

    } while(tecla != 'q');
    
    return 0;
}