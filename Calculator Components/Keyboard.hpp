#include <iostream>
#include "Key.hpp"
#include "CPU.hpp"
#include <vector>



using namespace std; 


class Keyboard{ // Contains the buttons
    Key* keys;
    char keyCount = 0;    

    CPU* cpu;
    public:
    Keyboard(CPU* cpu){setCPU(cpu);};
    Key getKey(Symbol s);
    bool insert(Key);
    bool remove(Key);
    bool removeKey(Symbol s);

    bool receive(Digit);

    void setCPU(CPU* cpu){if(cpu!=NULL)this->cpu= cpu;};
    CPU* getCPU();

};                      
