#pragma once
#include "note.h"
#include <string>

/*
Данный объект представляет собой тональность. 
Он представляет набор функций, посредством которых можно оценивать ноту, интервал и аккорд

getName() - Возвращает текущее имя тональности
сhangeName(char newName) - Изменяет тональность
getTone(Note note) - Выводит, на какой ступени тональности эта нота
*/

struct Key:Note {
    char name = 'C';   // aA,bB,cC,dD,eE,fF,gG (ascii A = 65, B = 66, a = 97, b = 98 и тд.)
    std::string sign;   // "is" - диез, "es" - бемоль

    bool dur[7] = {1, 1, 0, 1, 1, 1, 0};
    bool mol[7] = {1, 0, 1, 1, 0, 1, 1};

    std::string getName(){
        return std::string(1, name) + sign;
    }
    void changeName(char newName){
        name = newName;
    }

    int getTone(Note note){
        int result = 0;
        int note_h = note.name - 96;
        int ton_h = (name <= 71) ? (name + 32) : name;

        for(int x=0; x<note_h; ++x){
            ++ton_h;
            if(ton_h > 103){
                ton_h = 97;
            }
        }
        return 7 - (ton_h - 96);
    }
};