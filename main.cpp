// Данный бот будет использовать библиотеку tgBot.cpp
// Инструкция по установке: https://github.com/reo7sp/tgbot-cpp 
// Инструкция по библиотеке: http://reo7sp.github.io/tgbot-cpp/
#include <iostream>
#include "core/core.h"
int main() {
    note n;
    n.octave = 5;
    n.name = 'd';

    n.changeNote(-1);     //  d --> c
    n.changeOctave(-1);   //  5 --> 4

    std::cout << "октава: " << n.octave << std::endl;
    std::cout << "нота: " << n.name << std::endl;
    std::cout << "Высота в тональности " << 'c' << ": " << n.getTone('c') << std::endl;
    std::cout << "Высота в тональности " << 'a' << ": " << n.getTone('a') << std::endl;
    return 0;
}
