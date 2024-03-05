#include <iostream>
using namespace std;
class Computation {
public:
    int add(int a, int b) {
        return a + b;
    }

    float add(int a, float b) {
        return a + b;
    }

    double add(int a, double b) {
        return a + b;
    }

    int asciiSum(char a, char b) {
        return int(a) + int(b);
    }

    int asciiSum(char a, int b) {
        return int(a) + b; 
    }

    int defaultResult() {
        return -1;
    }
};
int main() {
    Computation calc;
    cout << "1 + 2 = " << calc.add(1, 2) << endl;
    cout << "1 + 2.5 = " << calc.add(1, 2.5f) << endl;
    cout << "1 + 3.5 = " << calc.add(1, 3.5) << endl;
    cout << "a + b = " << calc.asciiSum('a', 'b') << endl;
    cout << "a + 10 = " << calc.asciiSum('a', 10) << endl;
    cout << "Default result: " << calc.defaultResult() << endl;
    return 0;
}

