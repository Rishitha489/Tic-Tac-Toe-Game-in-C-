#include <iostream>
#include <cstdlib>
using namespace std;

char board[10] = {'0','1','2','3','4','5','6','7','8','9'};

void showBoard();
int checkWin();

int main() {
    int player = 1, choice, status;
    char mark;

    do {
        showBoard();
        player = (player % 2) ? 1 : 2;

        cout << "Player " << player << " turn: ";
        cin >> choice;

        mark = (player == 1) ? 'X' : 'O';

        // Validate Choice
        if (choice >= 1 && choice <= 9 && board[choice] == char(choice + '0')) {
            board[choice] = mark;
        } else {
            cout << "Invalid choice! Try again.\n";
            player--;       // redo same player's turn
            cin.ignore();
            cin.get();
        }

        status = checkWin();
        player++;

    } while (status == -1);

    showBoard();

    if (status == 1)
        cout << "Player " << --player << " wins!\n";
    else
        cout << "Game Draw!\n";

    return 0;
}

void showBoard() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    cout << "\n\tTIC TAC TOE\n\n";
    cout << "   " << board[1] << "   |   " << board[2] << "   |   " << board[3] << "\n";
    cout << "-------|-------|-------\n";
    cout << "   " << board[4] << "   |   " << board[5] << "   |   " << board[6] << "\n";
    cout << "-------|-------|-------\n";
    cout << "   " << board[7] << "   |   " << board[8] << "   |   " << board[9] << "\n\n";
}

int checkWin() {
    int wins[8][3] = {
        {1,2,3}, {4,5,6}, {7,8,9},    // rows
        {1,4,7}, {2,5,8}, {3,6,9},    // columns
        {1,5,9}, {3,5,7}              // diagonals
    };

    for (auto &w : wins) {
        if (board[w[0]] == board[w[1]] && board[w[1]] == board[w[2]])
            return 1; // win
    }

    for (int i = 1; i <= 9; i++)
        if (board[i] == char(i + '0'))
            return -1; // game continues

    return 0; // draw
}
