#include <iostream>
using namespace std;
int  sum(int n) {
    if (n <= 0) {
        return 0;
    }
    int sum = 0;
    int series_sum = 0; 
    for (int i = 1; i <= n; ++i) {
        series_sum += i; 
        sum += series_sum; 
    }
    return sum;
}
int main() {
    int n;
    cout << "Enter a number (n): ";
    cin >> n;   
    if (n <= 0) {
        cout << "Please enter a positive number." << endl;
    } else {
        int result = sum(n);
        cout << "Sum of the first " << n << " natural numbers: " << result << endl;
    }
    return 0;
}
