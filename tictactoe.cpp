#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class tictactoe {
public:
    tictactoe();
    void playgame();
private:
    int arr[3][3];
    int playerturn;
    void drawboard();
    int checkwin();
    void playermove();
    bool checkdraw();
    bool checkresult();
};
tictactoe::tictactoe() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            arr[i][j] = 0;
    }
    srand(time(0));
    playerturn = rand() % 2 + 1;
}
void tictactoe::playgame() {
    while (1) {
        system("cls");
        drawboard();
        playermove();
        if (checkresult())
            break;
    }
    cout << endl;
}
void tictactoe::drawboard() {
    cout << " Player 1(1) - Player 2(2)" << endl << endl;
    cout << " Turn: player " << playerturn << endl << endl;
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] == 0)
                cout << " ";
            else
                cout << arr[i][j];
            if (j == 2)
                continue;
            cout << " | ";
        }
        if (i == 2)
            continue;
        cout << endl << "___|___|___" << endl << "   |   |   " << endl;
    }
}
void tictactoe::playermove() {
    int row, col;
    bool correctmove = false;
    cout << endl << endl << " Make your Move!" << endl;
    while (!correctmove) {
        cout << "Enter Row (0-2): ";
        cin >> row;
        cout << "Enter Col (0-2): ";
        cin >> col;
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && arr[row][col] == 0) {
            arr[row][col] = playerturn;
            correctmove = true;
            playerturn = (playerturn == 1) ? 2 : 1; // Switch player turn
        } else {
            cout << "Invalid move, please enter again." << endl;
        }
    }
}
bool tictactoe::checkresult() {
    int check = checkwin();
    switch (check) {
        case 1:
            system("cls");
            drawboard();
            cout << endl << endl << " Player 1 Won!";
            return true;
        case 2:
            system("cls");
            drawboard();
            cout << endl << endl << " Player 2 Won!";
            return true;
        case -1:
            if (checkdraw()) {
                system("cls");
                drawboard();
                cout << endl << endl << " Match Drawn !";
                return true;
            }
            break;
    }
    return false;
}
int tictactoe::checkwin() {
    for (int player = 1; player < 3; player++) {
        for (int i = 0; i < 3; i++) {
            if (arr[i][0] == player && arr[i][1] == player && arr[i][2] == player)
                return player;
            if (arr[0][i] == player && arr[1][i] == player && arr[2][i] == player)
                return player;
        }
        if (arr[0][0] == player && arr[1][1] == player && arr[2][2] == player)
            return player;
        if (arr[0][2] == player && arr[1][1] == player && arr[2][0] == player)
            return player;
    }
    return -1;
}
bool tictactoe::checkdraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] == 0)
                return false;
        }
    }
    return true;
}
int main() {
    tictactoe obj;
    obj.playgame();
    system("pause");
    return 0;
}
