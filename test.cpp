#include <iostream>
#include <vector>

int main() {
    // Matriz para representar os dígitos de 0 a 9 em um formato de display de 7 segmentos
    const std::vector<std::string> digitos = {
        "abcdef",  // 0
        "bc",      // 1
        "abdeg",   // 2
        "abcdg",   // 3
        "bcfg",    // 4
        "acdfg",   // 5
        "acdefg",  // 6
        "abc",     // 7
        "abcdefg", // 8
        "abcdfg"   // 9
    };

    // Número a ser exibido
    std::string numero = "12345";

    // Loop para percorrer cada dígito do número
    for (char digito : numero) {
        int d = digito - '0'; // Converte o caractere do dígito para um número inteiro

        // Loop para percorrer os segmentos do dígito e imprimi-los
        for (char segmento : digitos[d]) {
            if (segmento == 'a') std::cout << "  __  ";
            if (segmento == 'b') std::cout << " |  | ";
            if (segmento == 'c') std::cout << " __|  ";
            if (segmento == 'd') std::cout << " | __| ";
            if (segmento == 'e') std::cout << " | __  ";
            if (segmento == 'f') std::cout << " |  __| ";
            if (segmento == 'g') std::cout << "  |__| ";
        }

        // Espaço entre os dígitos
        std::cout << " ";
    }

    std::cout << std::endl;

    return 0;
}
