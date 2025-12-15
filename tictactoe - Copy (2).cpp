#include <iostream>
using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

char player = 'X';

void displayBoard() {
    cout << endl;
    for(int i = 0; i < 3; i++) {
        cout << " ";
        for(int j = 0; j < 3; j++) {
            cout << board[i][j];
            if(j < 2) cout << " | ";
        }
        cout << endl;
        if(i < 2) cout << "---|---|---" << endl;
    }
    cout << endl;
}

void changePlayer() {
    if(player == 'X')
        player = 'O';
    else
        player = 'X';
}

bool checkWin() {
    // Rows & Columns
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }

    // Diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return false;
}

bool checkDraw() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void makeMove() {
    int choice;
    cout << "Player " << player << ", enter position (1-9): ";
    cin >> choice;

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if(choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Invalid move! Try again.\n";
        makeMove();
    } else {
        board[row][col] = player;
    }
}

int main() {
    cout << "===== TIC TAC TOE GAME =====" << endl;

    while(true) {
        displayBoard();
        makeMove();

        if(checkWin()) {
            displayBoard();
            cout << "?? Player " << player << " wins!" << endl;
            break;
        }

        if(checkDraw()) {
            displayBoard();
            cout << "?? Game Draw!" << endl;
            break;
        }

        changePlayer();
    }

    return 0;
}
