#pragma once
#include <string>

/*
Эта структура представляет собой ноту. Базовый кирпич музыки

Атрибуты: 
  octave - октава ноты.
  name - название ноты.
  sign - знак.

Методы: 
  
*/

struct Note{
    public:
        int octave;       // 1 - субконтр, 2 - контр, 3 - большая,..
        char name;        // a,b,c,d,e,f,g - наименование нот (по ascii a = 97, b = 98 и тд.) (Да, я знаю, что си бекар - это "h", но здесь удобней сделать си символом b. Все ботаники - идите в баню)
        std::string sign; // "is" - диез, 'es' - бемоль, '' - бекар

        int getNextHalfTones(){
            if(sign == ""){
                if(name == 'b' || name == 'e') return 1;
                return 2;
            }
            if(sign == "is"){
                if(name == 'b' || name == 'e') return 0;
                return 1;
            }
            if(sign == "es"|| sign == "s"){
                if(name == 'b' || name == 'e') return 2;
                return 3;
            }
            return -1;
        }

        Note(){
            octave = 5;
            name = 'c';
            sign = "";
        }
};