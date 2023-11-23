#include <iostream>
//#include <windows.h>
// #include "Calculator Components\Calculator.hpp"
// #include "Calculator Components\CPU.hpp"
#include "Calculator Components/DisplayNat.hpp"
// #include "Calculator Components\Key.hpp"
// #include "Calculator Components\Keyboard.hpp"
#include "Calculator Components/Console.hpp"
#include <set>

using namespace std; 

// Abstrair: Enxergar as partes de um sistema.
// Encapsulamento: Esconder coisas dentro de uma capsula (a classe).

// void splitToStringPosition(string s, vector<string>* sv, char dem){
//     int conc = 0;
//     if (sv->size() != 0)
//     {
//         conc = 1;
//     }

//     // até dá para colocar a condição dentro do laço principal, contudo ele afeta a estrutura da string como um todo, afetando o espaçamento
//     if (conc == 1){
//         for (int i = 0; i < sv->size(); i++)
//         {
//             sv->at(i) += "  ";
//         }
//     }

//     for (int i = 0, j = 0; i < s.size(); i++)
//     {  
//         if(s[i] != dem){
//             // if(conc == 1)
//             //     sv->at(j) += " ";
//             sv->at(j) += s.substr(i, 1);
//         }else{
//             j++;
//         }
//     }
//     // if (conc == 1)
//     // {
//     //     sv->at(0).at(sv->at(0).find_first_of("[^ ;\n]")) += ' ';
//     // }
    
//     conc = 1;
// }



int main(int argc, char** argv){
    // Console::init(0,0);
    //SetConsoleOutputCP(65001);
    Display* display1 = new DisplayNat();
    Console::init(10,5);
    // vector<string> sevenSegments(9);
    // string c =  " 3333\n     3\n     3\n     3\n 3333\n     3\n     3\n     3\n 3333\n";
    // string d = "  2222\n     2\n     2\n     2\n  2222\n2\n2\n2\n  2222\n";
    // string a;
    // splitToStringPosition(c, &sevenSegments, '\n');
    // splitToStringPosition(d, &sevenSegments, '\n');

    display1->add(ONE);
    display1->add(TWO);
    // for (int i = 0; c[i] != '\n'; i++)
    // {
    //     a += c.substr(i, 1);
    // }
    // cout << a << endl;

    // cout << "amor" << endl;

    // set<string> uniqueSevenSegments;
    // for (auto& segment : sevenSegments) {
    //     if (uniqueSevenSegments.find(segment) == uniqueSevenSegments.end()) {
    //         uniqueSevenSegments.insert(segment);
    //     }
    // }

    // Print the unique strings in the vector to the console.
    // for (auto& segment : uniqueSevenSegments) {
    //     cout << "[" << i << "]: " << segment << endl;
    //     i++;
    // }

    // for(auto& segment : sevenSegments){
    //      cout << "[" << i << "]: " << segment << endl;
    //      i++;
    // }
    // cout << sevenSegments[0];
    

    // cout << sevenSegments.size();

    // stringstream ss(c);

    // string line;
    // while (getline(ss, line, '\n')) {
    //     sevenSegments.push_back(line);
    // }

    // Agora 'parts' contém as partes separadas
    // for (const string& part : sevenSegments) {
    //     cout << part << endl;
    // }
    
    // for (int i = 0; i < sevenSegments.size(); i++)
    // {
    //     cout << sevenSegments[i] << endl;
    // }
    
    
    // display1.add(TWO);
    // display1.add(FOUR);
    // display1.add(THREE);
    // display1.add(FOUR);
    // display1.setDecimalSeparator()c;
    // display1.clear();
  

    // display1.add(ONE);
    // Console::setCursor(0,)
    // display1.add(TWO);
    // display1.add(THREE);
    // display1.add(FOUR);
    // display1.setDecimalSeparator();
    // display1.add(ZERO);
    // display1.add(FIVE);
    // display1.add(SIX);
    // display1.add(SEVEN);
    // display1.add(EIGHT);

    // Console::init(0,0);
    // display1.add(ONE);
    // display1.add(ZERO);
    // display1.add(TWO);
    // CPU cpu1;
    // Keyboard keyboard1;


    // keyboard1.setCPU(&cpu1);
    // Calculator calculator1;

    // calculator1.getKeyboard().getKey("1").press();
    // calculator1.getKeyboard().getKey("+").press();
    // calculator1.getKeyboard().getKey("1").press();
    // calculator1.getKeyboard().getKey("=").press();
    // Console::setCursor(25, 0);
    


    return 0;
}