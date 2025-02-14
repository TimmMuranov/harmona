#pragma once

struct note{
    public:
        int octave;  // 1 - субконтр, 2 - контр, 3 - большая,..
        char name;   // a,b,c,d,e,f,g - наименование нот (по ascii a = 97, b = 98 и тд.)

        int getTone(int n, char key){
            n -= 96;
            for(int x=0; x<n; ++x){
                key++;
                if(key > 103){
                    key = 97;
                }
            }
            return 7 - (key - 96);
        }
        int getTone(char key){
            return getTone(name, key);
        }

        void changeNote(int index){
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
    private:
};