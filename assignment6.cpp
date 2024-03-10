#include<iostream>
using namespace std;

class sample {
public:
    int Compute(int (sample::*func)(int), int n) {
        return (this->*func)(n);
    }
    int findFactorial(int n) {
        int fact = 1;
        for(int i = 1; i <= n; i++) {
            fact *= i;
        }
        return fact;
    }
    int findSquare(int n) {
        return n * n;
    }
    int findCube(int n) {
        return n * n * n;
    }
};
int main(int argc, char *argv[]) {
    sample obj;
    int factorial = obj.Compute(&sample::findFactorial, 5);
    cout << "Factorial of 5: " << factorial << endl;
    int square = obj.Compute(&sample::findSquare, 5);
    cout << "Square of 5: " << square << endl;
    int cube = obj.Compute(&sample::findCube, 5);
    cout << "Cube of 5: " << cube << endl;
    return 0;
}