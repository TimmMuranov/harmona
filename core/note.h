#pragma once

/*
Эта структура представляет собой ноту как базовый кирпич музыки

Атрибуты: 
  octave - октава ноты.
  name - название ноты.

Методы:
  getTone(char key) - определяет ступень нотыв тональности key
*/

struct Note{
    public:
        int octave;  // 1 - субконтр, 2 - контр, 3 - большая,..
        char name;   // a,b,c,d,e,f,g - наименование нот (по ascii a = 97, b = 98 и тд.) (Да, я знаю, что си бекар - это "h". Все ботаники - идите в баню)
        char sign;   // '+' - диез, '-' - бемоль, '~' - бекар

        void changeNote(int index){
            if(name + index > 103 || name + index < 97){return;}
            name += index;
        }

        void changeOctave(int index){
            if (name + index < 0) {return;}
            octave += index;
        }

        Note(){
            octave = 5;
            name = 'c';
            sign = '~';
        }
};