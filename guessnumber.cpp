#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
class NumberGuesser {
private:
    int start, end, guess, count, rno, chances;
public:
    void startGame() {
        start = 1; 
        end = 100; 
        rno = rand() % (end - start + 1) + start;
        chances = floor(log2(end - start + 1));
        cout << "You have given " << chances << " chances to guess a computer generated number between 1 and 100." << endl;
        count = 0;
        while (count < chances) {
            count++;
            cout << "Enter your guess : ";
            cin >> guess;
            if (guess > rno) {
                cout << "Your guess is a little more." << endl;
            } else if (guess < rno) {
                cout << "Your guess is a little less." << endl;
            } else {
                break;
            }
        }
        if (guess == rno) {
            cout << "Hey, you guessed the number in " << count << " chances and the number was " << rno << endl;
        } else {
            cout << "You've exhausted all your chances of guessing. Better luck next time." << endl;
            cout << "The computer generated number was " << rno << endl;
        }
        cout << "Have a nice day." << endl;
    }
};
int main() {
    NumberGuesser game;
    game.startGame();
    return 0;
}
