#pragma once
/* Нота. Ни больше ни меньше.
 * Методы:
 *   get_name() - возвращает имя ноты.
 *   change_name(char) - изменяет имя.
 *   get_sign() - возвращает знак.
 *   change_sign() - изменяет знак.
 *   get_octave() - возвращает октаву.
 *   change_octave() - изменяет октаву.
 *   get_height_comon() - возвращает высоту ноты (от ля 1 октавы) без учета знаков.
 *   get_height_half_t() - возвращает высоту в полутонах.
 *   
 * */
struct Note{
	public:

//---------------- Функции базовых значений ------------------

		char get_name() {return name;}

		void change_name(char new_name){
			if(new_name > 'g' || new_name < 'a') {return;}
			name = new_name;
		}

		int get_sign() {return sign;}

		void change_sign(int new_sign){
			if(new_sign > 2 || new_sign < -2) {return;}
			sign = new_sign;
		}

		int get_octave() {return octave;}

		void change_octave(int new_octave){
			if(new_octave < 1) {return;}
			octave = new_octave;
		}

//------------------------- Функции высоты ноты -----------------------

		int get_height_comon(){
		 	int note_num = 0;
			char test = 97;
			for(int x=1; x<=7; ++x){
				if(name == test){
				       	note_num = x;
					break;
				}
				++test;
			}
			if(note_num == -1) return -1;
			return (octave - 1) * 7 + note_num;
		}

		int get_height_half_t(){
			int answer = (octave - 1) * 12;
			char test = 'a';
			for(int x=0; x<7; ++x){
				if(test == name) {break;}
				if(test == 'b' || test == 'e'){
					++answer;
				} else {
					answer += 2;
				}
				++test;
			}
			return answer + sign;
		}
	private:
		char name = 'a';     // имя ноты
		int octave = 2;      // октава
		int sign = 0;        // 0-бекар, 1 - диез, 2 - дубльдиез, -1 - бемоль, -2 - дубльбемоль
};
