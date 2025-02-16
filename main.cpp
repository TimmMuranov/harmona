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
    std::cout << "До следуюшей ноты полутонов " << n.getNextHalfTones() << std::endl;
//------------- Тест тональности ----------------------
    std::cout << "Тест тональности начинается: \n";
    Key k;
    k.sign = "";
    k.changeName("d");
    std::cout << k.getName() << std::endl;
    std::cout << k.getHeight(n) << std::endl;
    k.changeName("bis");
    std::cout << k.getName() << std::endl;
    std::cout << k.getHeight(n) << std::endl;
    return 0;
}
