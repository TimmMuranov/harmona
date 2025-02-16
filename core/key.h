#pragma once
#include "note.h"
#include <string>
#include <array>

/*
Данный объект представляет собой тональность. 
Он представляет набор функций, посредством которых можно оценивать ноту, интервал и аккорд

getName() - Возвращает текущее имя тональности
сhangeName(char newName) - Изменяет тональность
getTone(Note note) - Выводит ступень, на которой расположена данная нота
*/

struct Key {
    public:

    char name = 'c';   // aA,bB,cC,dD,eE,fF,gG (ascii A = 65, B = 66, a = 97, b = 98 и тд.)
    std::string sign;   // "is" - диез, "es" - бемоль

    std::string getName(){
        return std::string(1, name) + sign;
    }
    void changeName(std::string newName){
        if  (!(newName[0] >= 'A' && newName[0] <= 'G') &&
        !(newName[0] >= 'a' && newName[0] <= 'g')){
        return;
        }

        if (newName.length() > 1){
            std::string suffix = newName.substr(1);
            if (suffix != "is" && suffix != "es" && suffix != "s"){
            return;
            }
        }
        name = newName[0]; // Сохранение первой буквы
        if (newName.length() > 1){
            sign = newName.substr(1); // Сохранение остального
        }
    }

    int getHeight(Note note){
        int result;
        int note_h = note.name - 96;
        int ton_h = (name <= 71) ? (name + 32) : name;

        for(int x=0; x<note_h; ++x){
            ++ton_h;
            if(ton_h > 103){
                ton_h = 97;
            }
        }
        return 8 - (ton_h - 96);
    }

    int getSign(int k){
    }

    private:
    bool dur[7] = {1, 1, 0, 1, 1, 1, 0};  // Расстояние между ступенями в мажоре
    bool mol[7] = {1, 0, 1, 1, 0, 1, 1};  // Расстояние между ступенями в миноре 
    bool dist[7] = {1, 0, 1, 1, 0, 1, 1}; // Расстояние между нотами (a-b, b-c, c-d,..)
};