#include "Calculator Components/CPULucio.hpp"

int main(){
    BufferDigits buffer(12.12);
    BufferDigits buffer2(2);

    auto teste = buffer * buffer2;

    teste.print();

    return 0;
}