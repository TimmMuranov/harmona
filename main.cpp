#include <iostream>
#include "core/core.h"
int main() {
//------------- Тест ноты ----------------------------
    std::cout << "Тест ноты начинается: \n";
    Note n;
    n.octave = 5;
    n.name = 'd';

    n.changeNote(-1);     //  d --> c
    n.changeOctave(-1);   //  5 --> 4

    std::cout << "октава: " << n.octave << std::endl;
    std::cout << "нота: " << n.name << std::endl;
//------------- Тест тональности ----------------------
    std::cout << "Тест тональности начинается: \n";
    Key k;
    k.sign = "";
    std::cout << k.getName() << std::endl;
    std::cout << k.getTone(n)[0] << " знак " << k.getTone(n)[1] << std::endl;
    k.changeName('B');
    std::cout << k.getTone(n)[0] << " знак " << k.getTone(n)[1] << std::endl;
    return 0;
}
