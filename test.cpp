#include <iostream>

#include "core/core.h"

using namespace std;

Mus_system sys;
Note n;

char k;
char n_n;
int s;

int main(){
    cout << endl << "------------------------------" << endl;
    cout << "Enter test number or -1 to exit\n";
    int test_number;
    cin >> test_number;
    if(test_number = -1) return 0;
    else if (test_number == 1) sys_test();
    else if (test_number == 2) get_sygn_test();
    else if (test_number == 3) note_test();
    return 0;
}
//--------- Тест системы -----------------------------
void sys_test() { //1
    cout << "Start Mus_system test:\n\n";
    cout << "Enter note,t name, sign (0 - bekar, 1 - dies, -1 - bemol) and key (d, m)\n";
    cin >> n_n;
    cin >> s;
    cin >> k;
    n.change_name(n_n);
    n.change_sign(s);
    cout << "note sign " << n.get_sign() << endl;
    auto scale = sys.get_scale(n, k);

    cout << "dur scale: ";
    for(int x=0; x<7; ++x){
	    cout << scale[x].get_name();
    }
    cout << endl;
    
    cout << "Note distance ";
    for (int x=0; x<7; ++x){
	    cout << scale[x].get_height_half_t() << " ";
    }
    cout << endl;

    cout << "scale octave: ";
    for (int x=0; x<7; ++x){
	    cout << scale[x].get_octave();
    }
    cout << endl;

    cout << "scale sign: ";
    for (int x=0; x<7; ++x){
	    cout << scale[x].get_sign();
    }
}
//---------------------------------------------------------
void get_sygn_test(){//2
    cout << "Enter key (note, sign & key) for sign testing\n";
    cin >> n_n;
    cin >> s;
    cin >> k;
    n.change_name(n_n);
    n.change_sign(s);
    cout << "signs in " << n_n << "(" << s << ") " << k << ": " << sys.get_signs(n, k) << endl;

    cout << endl << "-------------------------------" << endl;
}
//----------- Тест ноты ------------------------------
void note_test(){//3
    cout << "Start Note test:\n\n";
    n.change_octave(2);
    n.change_name('c');
    n.change_sign(1);
    cout << "Name: " << n.get_name() << endl;
    cout << "Octave: " << n.get_octave() << endl;
    cout << "Sign: " << n.get_sign() << endl;
    cout << "Обычная высота: " << n.get_height_comon() << endl;
    cout << "Полутоновая высота: " << n.get_height_half_t() << endl;
}

