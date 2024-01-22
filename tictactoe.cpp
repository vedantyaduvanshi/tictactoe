#include <iostream>
#include <vector>

using namespace std;

// Function to display the Tic Tac Toe board
void displayBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char symbol) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) {
        return true;
    }

    return false;
}

// Function to check if the board is full (tie)
bool checkTie(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false; // Board is not full
            }
        }
    }
    return true; // Board is full
}

int main() {
    // Initialize the board
    vector<vector<char>> board(3, vector<char>(3, ' '));

    // Define player symbols
    char player1 = 'X';
    char player2 = 'O';

    // Display the initial board
    displayBoard(board);

    // Main game loop
    while (true) {
        // Player 1's turn
        int row, col;
        cout << "Player 1's turn (row and column): ";
        cin >> row >> col;

        // Check if the selected cell is empty
        if (board[row][col] == ' ') {
            board[row][col] = player1;
        } else {
            cout << "Cell already occupied. Try again." << endl;
            continue; // Ask for a new move
        }

        // Display the updated board
        displayBoard(board);

        // Check if Player 1 wins
        if (checkWin(board, player1)) {
            cout << "Player 1 wins!" << endl;
            break;
        }

        // Check for a tie
        if (checkTie(board)) {
            cout << "It's a tie!" << endl;
            break;
        }

        // Player 2's turn
        cout << "Player 2's turn (row and column): ";
        cin >> row >> col;

        // Check if the selected cell is empty
        if (board[row][col] == ' ') {
            board[row][col] = player2;
        } else {
            cout << "Cell already occupied. Try again." << endl;
            continue; // Ask for a new move
        }

        // Display the updated board
        displayBoard(board);

        // Check if Player 2 wins
        if (checkWin(board, player2)) {
            cout << "Player 2 wins!" << endl;
            break;
        }
    }

    return 0;
}
