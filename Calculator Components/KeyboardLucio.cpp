#include "KeyboardLucio.hpp"
#include "cstring"


void KeyboardLucio::addKey(Key *key) {
	for(int i = 0; i < this->keysCount; i++){
		if(this->keys[i] == key) throw "Key is already inserted!";
	}
  this->keys[this->keysCount++] = key;
  key->setKeyboard(this); /* Connect this keyboard with new key */
}

void KeyboardLucio::removeKey(Key *key) { 
	/* TODO */
	for(int i=0; i < this->keysCount; i++){
		if(this->keys[i] == key){
			this->keys[i] = nullptr;
			this->keysCount--;
		}
	}
	throw "Key not Found!";
}

Key *KeyboardLucio::findKey(Symbol symbol) {
  for (char i = 0; i < this->keysCount; i++)
    if (strcmp(symbol,this->keys[i]->getSymbol()))
      return this->keys[i];

  throw "Key not found!";
}

void KeyboardLucio::setCpu(Cpu *cpu) { this->cpu = cpu; }

Cpu *KeyboardLucio::getCpu() { return this->cpu; }
