#include <iostream>
#include <string>
using namespace std;
class User {
private:
    string name;
    int birthYear;
    int birthMonth;
    int birthDay;
    double salary;
public:
    User(const string& n, int year, int month, int day, double sal)
        : name(n), birthYear(year), birthMonth(month), birthDay(day), salary(sal) {}
    int operator==(const User& other) const {
        if (birthYear < other.birthYear)
            return 1;
        else if (birthYear > other.birthYear)
            return -1;
        else {
            if (birthMonth < other.birthMonth)
                return 1;
            else if (birthMonth > other.birthMonth)
                return -1;
            else {
                if (birthDay < other.birthDay)
                    return 1;
                else if (birthDay > other.birthDay)
                    return -1;
                else
                    return 0;
            }
        }
    }
    double operator+(const User& other) const {
        return (salary + other.salary) / 2.0;
    }
    User operator+(const int& percent_increment) const {
        double increment_factor = (percent_increment + 100) / 100.0;
        double new_salary = salary * increment_factor;
        return User(name, birthYear, birthMonth, birthDay, new_salary);
    }
    void display() const {
        cout << "Name: " << name << ", Birthdate: " << birthDay << "/" << birthMonth << "/" << birthYear
             << ", Salary: " << salary << endl;
    }
};
int main() {
    User user1("John Doe", 1990, 5, 15, 50000.0);
    User user2("Jane Smith", 1985, 9, 25, 60000.0);
    int result = user1 == user2;
    cout << "Comparison result: " << result << endl;
    double average_sal = user1 + user2;
    cout << "Average salary: " << average_sal << endl;
    User user1_with_increment = user1 + 5;
    cout << "User 1 with 5% increment: ";
    user1_with_increment.display();
    User user2_with_increment = user2 + 10;
    cout << "User 2 with 10% increment: ";
    user2_with_increment.display();
    return 0;
}

