#include <iostream>
#include <string>
using namespace std;
class TotalWord {
private:
    string str;
public:
    TotalWord(const string& s) : str(s) {}
    int calculateTotalWords() const {
        int wordCount = 0;
        bool inWord = false;
        for (char c : str) {
            if (isspace(c)) {
                inWord = false;
            } else {
                if (!inWord) {
                    wordCount++;
                    inWord = true;
                }
            }
        }
        return wordCount;
    }
};
int main() {
    string inputString;
    cout << "Enter a string: ";
    getline(cin, inputString);
    TotalWord wordCounter(inputString);
    cout << "Total words in the string: " << wordCounter.calculateTotalWords() << endl;
    return 0;
}

