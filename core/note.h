#pragma once
#include "core.h"

struct note{
    public:
        int octave; // 1-субконтр, 2-контр, 3-большая, 4-малая, 5-первая, 6-вторая,..
        int note_name; // 
        char sign;

        int getHeight(int height){
            if (sign == '~'){
                return height;
            } else if(sign == '+'){
                return ++height;
            } else if(sign == '-'){
                return --height;
            }
        }
        
}