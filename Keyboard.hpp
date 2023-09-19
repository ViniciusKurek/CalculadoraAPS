#include <iostream>
#include "Key.hpp"
#include <vector>

using namespace std; 


class Keyboard{ // Contains the buttons
    vector<Key> digitKeys;
    vector<Key> operationKeys;
    

    public:
    void get(vector<Key>);
    void insert(Key);
    void remove(Key);

};                      
