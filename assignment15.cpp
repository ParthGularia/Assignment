#include <iostream>
using namespace std;
class ClassA;
class ClassB;
class ClassA {
private:
    int numA;
public:
    ClassA(int num) : numA(num) {}

    friend int sum(const ClassA& objA, const ClassB& objB);
};
class ClassB {
private:
    int numB;
public:
    ClassB(int num) : numB(num) {}
    friend int sum(const ClassA& objA, const ClassB& objB);
};
int sum(const ClassA& objA, const ClassB& objB) {
    return objA.numA + objB.numB;
}
int main() {
    int num1, num2;
    cout << "Enter the value for num1: ";
    cin >> num1;
    cout << "Enter the value for num2: ";
    cin >> num2;
    ClassA objA(num1);
    ClassB objB(num2);
    cout << "Sum of private members: " << sum(objA, objB) << endl;
    return 0;
}
