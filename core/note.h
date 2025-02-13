#pragma once
#include "core.h"

struct note{
    public:
        int octave; // 1 - субконтр, 2 - контр, 3 - большая,..
        char name; // a,b,c,d,e,f,g - наименование нот (по ascii a = 97, b = 98 и тд.)
        float height; // высота ноты от до первой октавы
        char sign; // "+" = диез, "-" = бемоль,  "~" = отсутствие знака

        int getHeight(int height){
            if (sign == '~'){
                return name - 96; // 1 - нота a
            } else if(sign == '+'){
                return (height - 0.5) - 96;
            } else if(sign == '-'){
                return (height - 0.5) - 96;
            }
        }

        void change(int index){
            if(index = 0){
                return;
            }
            if(index > 0){
                for (int x=0; x<index; ++x){
                    if(name < 103){
                        ++name;
                    } else {
                        name = 97;
                        ++octave;
                    }
                }
            }
            if(index < 0){
                for (int x=0; x>index; ++index){
                    if(name > 97){
                        --name;
                    } else {
                        name = 103;
                        --octave;
                    }
                }
            }
        }
        
}