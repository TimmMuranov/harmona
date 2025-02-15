#pragma once
#include "note.h"
#include <string>
#include <array>

/*
Данный объект представляет собой тональность. 
Он представляет набор функций, посредством которых можно оценивать ноту, интервал и аккорд

getName() - Возвращает текущее имя тональности
сhangeName(char newName) - Изменяет тональность
getTone(Note note) - Выводит массив. Первый элемент - ступень в тональности, второй - альтерация
*/

struct Key {
    char name = 'c';   // aA,bB,cC,dD,eE,fF,gG (ascii A = 65, B = 66, a = 97, b = 98 и тд.)
    std::string sign;   // "is" - диез, "es" - бемоль

    bool dur[7] = {1, 1, 0, 1, 1, 1, 0};
    bool mol[7] = {1, 0, 1, 1, 0, 1, 1};

    std::string getName(){
        return std::string(1, name) + sign;
    }
    void changeName(char newName){
        name = newName;
    }

    std::array<int, 2> getTone(Note note){
        int result = 0;
        int sign = 0; // 0 - нет знака, 1 - диез, -1 - бемоль
        int note_h = note.name - 96;
        int ton_h = (name <= 71) ? (name + 32) : name;

        for(int x=0; x<note_h; ++x){
            ++ton_h;
            if(ton_h > 103){
                ton_h = 97;
            }
        }
        result = 7 - (ton_h - 96);
        if(name > 71){

        } else {

        }
        return {result, sign};
    }
};