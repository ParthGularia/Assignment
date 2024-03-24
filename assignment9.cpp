#include <iostream>
using namespace std;
class add_overload {
private:
    int x;
    int y;
public:
    add_overload (int xVal = 0, int yVal = 0) : x(xVal), y(yVal) {}

    void display() const {
        cout << "(" << x << ", " << y << ")";
    }
    add_overload  friend operator+(const add_overload & p1, const add_overload & p2);
};
add_overload  operator+(const add_overload & p1, const add_overload & p2) {
    int newX = p1.x + p2.x;
    int newY = p1.y + p2.y;
    return add_overload (newX, newY);
}
int main() {
   add_overload  p1(7, 3);
   add_overload  p2(4, 9);
   add_overload  result = p1 + p2;
    cout << "Result of addition: ";
    result.display();
    cout << endl;
    return 0;
}
