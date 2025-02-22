#pragma once
#include <string>
#include <array>
#include "note.h"
using namespace std;
struct Mus_system{
	private:
   	char comon_mus_scale[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    	int dur_tones[6] = {2, 2, 1, 2, 2, 2};
    	int mol_tones[6] = {2, 1, 2, 2, 1, 2};

	public:
//------------- Построение гаммы -----------------------
    	array<Note, 7> get_scale(Note n, char key){
        	array<Note, 7> answer;
		char n_name = n.get_name();
		int n_octave = n.get_octave();
		
		for(int x=0; x<=7; ++x){
			n_name = n.get_name() + x;
			n_octave = n.get_octave();
			if(n_name > 'g'){
				n_name -= 7;
				++n_octave;
			}
			answer[x].change_name(n_name);
			answer[x].change_octave(n_octave);
		}

		int key_tones[6];
		if(key == 'd'){
			swap(key_tones, dur_tones);
		} else if(key == 'm'){
			swap(key_tones, mol_tones);
		}

		int dist = 0;
		answer[0].change_sign(n.get_sign());

		if(key == 'd' || key == 'm'){
			for(int x=0; x<6; ++x){
				dist = answer[x+1].get_height_half_t() - answer[x].get_height_half_t();
				if(dist < key_tones[x]){
					answer[x+1].change_sign(answer[x+1].get_sign() + 1);
				}
				if(dist > key_tones[x]){
					answer[x+1].change_sign(answer[x+1].get_sign() - 1);
				}
				if(dist == key_tones[x]){
					answer[x+1].change_sign(0);
				}
			}
		}
		return answer;
	}

	array<Note, 7> get_scale(Note n){return get_scale(n, '-');}
	array<Note, 7> get_scale(){
		Note n;
		n.change_name('a');
		return get_scale(n, '-');
	}

//----------- Определение знаков -----------------------

	int get_signs(Note n, char key){
		int answer = 0; // отрицательное число - к-во бемолей, положительное число - к-во диезов.
		array<Note, 7> scale = get_scale(n, key);
		for(int x=0; x<6; ++x){
			answer += scale[x].get_sign();
		}
		return answer;
	}
//----------------------------------------------------------


};
