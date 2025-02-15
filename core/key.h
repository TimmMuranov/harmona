#pragma once
#include "note.h"
struct Key:Note {

    char key;    // 'd' - мажор, 'm' - минор
    char name;   // a,b,c,d,e,f,g - наименование нот (по ascii a = 97, b = 98 и тд.)
    char sign;   // '+' - диез, '-' - бемоль, '~' - бекар

    bool dur[7] = {1, 1, 0, 1, 1, 1, 0};
    bool mol[7] = {1, 0, 1, 1, 0, 1, 1};

    int getTone(Note note){
        int result = 0;
        //...я запарился...
        return result;
    }

    Key(){
        key = 'd';
        name = 'c';
        sign = '~';
    }

};