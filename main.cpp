#include <iostream>
#include <cmath> // Для функции round

int main() {
    float t = 880;
    float c = 1.05947328255896;
    
    for (int x = 0; x < 13; ++x) {
        int t1 = std::round(t); // Округляем до ближайшего целого
        std::cout << t1 << "   ";
        std::cout << t << std::endl;
        
        t /= c;
    }
    
    return 0;
}
