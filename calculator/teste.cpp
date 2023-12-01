#include "Calculator Components/CPULucio.hpp"
#include <iostream>

int main(){
    BufferDigits buffer(400);

    auto b = buffer.percent();

    b.print();

    return 0;
}