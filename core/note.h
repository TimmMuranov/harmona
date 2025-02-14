#pragma once

struct note{
    public:
        int octave;  // 1 - субконтр, 2 - контр, 3 - большая,..
        char name;   // a,b,c,d,e,f,g - наименование нот (по ascii a = 97, b = 98 и тд.)

        int getTone(char key){
            char n = name;
            if(key < 97 || key > 103){
                return -1;
            }
            n -= 96;
            for(int x=0; x<n; ++x){
                key++;
                if(key > 103){
                    key = 97;
                }
            }
            return 7 - (key - 96);
        }

        void changeNote(int index){
            if(name + index > 103 || name + index < 97){return;}
            name += index;
        }

        void changeOctave(int index){
            if (name + index < 0) {return;}
            octave += index;
        }
    private:
};