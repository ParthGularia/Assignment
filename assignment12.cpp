#include<iostream>
using namespace std;
class smallUnit {
private:
    float inches;
public:
    smallUnit(float in) : inches(in) {}
    operator float() const {
        return inches / 12.0f;
    }
};
class largerUnit {
private:
    float feet;
public:
    largerUnit() : feet(0) {}
    void display() const {
        cout << "Measurement in feet: " << feet << endl;
    }
    largerUnit& operator=(const smallUnit& obj) {
        feet = obj;
        return *this;
    }
};
int main() {
    float inchesInput;
    cout << "Enter measurement in inches: ";
    cin >> inchesInput;
    smallUnit smallObj(inchesInput);
    largerUnit largeObj;
    largeObj = smallObj;
    largeObj.display();  
    return 0;
}
