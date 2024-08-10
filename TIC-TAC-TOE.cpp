#include <iostream>
using namespace std;

// Function to display the current state of the tic-tac-toe board
void showBoard(char board[3][3]) {
    cout << "-----------------" << endl;
    for (int row = 0; row < 3; row++) {
        cout << " | ";
        for (int col = 0; col < 3; col++) {
            cout << board[row][col] << " | ";
        }
        cout << endl << "-----------------" << endl;
    }
}

// Function to check for a win or a draw
int evaluateBoard(char board[3][3]) {
    // Check each row and column for a win
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')) {
            return (board[i][0] == 'O' || board[0][i] == 'O') ? 1 : 2;
        }
    }
    // Check diagonals for a win
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return (board[1][1] == 'O') ? 1 : 2;
    }

    // Check if the game is still ongoing
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == ' ') {
                return 3; // Game is still ongoing
            }
        }
    }
    return 0; // Game is a draw
}

// Function to manage the tic-tac-toe game
void playTicTacToe() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char player1Choice, player2Choice;
    int turnCount = 0;

    // Get a valid input for player1's symbol
    do {
        cout << "Player 1, choose your symbol (O or X): ";
        cin >> player1Choice;
        if (player1Choice != 'O' && player1Choice != 'X') {
            cout << "Invalid choice. Please choose 'O' or 'X'." << endl;
        }
    } while (player1Choice != 'O' && player1Choice != 'X');

    // Assign the opposite symbol to player2
    player2Choice = (player1Choice == 'O') ? 'X' : 'O';
    cout << "Player 2, you will be: " << player2Choice << endl;

    // Show the initial empty board
    showBoard(board);

    // Main loop for the game
    while (turnCount < 9) {
        int row, col;
        // Determine the current player
        char currentPlayer = (turnCount % 2 == 0) ? player1Choice : player2Choice;
        cout << "Player " << ((turnCount % 2 == 0) ? "1" : "2") << " (" << currentPlayer << "), enter row and column (0, 1, 2): ";
        cin >> row >> col;

        // Validate the player's move
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Please try again." << endl;
            continue;
        }

        // Place the player's symbol on the board
        board[row][col] = currentPlayer;
        showBoard(board);

        // Check the board for a win or draw
        int status = evaluateBoard(board);
        if (status == 1) {
            cout << "Player 1 (with O) wins!" << endl;
            break;
        } else if (status == 2) {
            cout << "Player 2 (with X) wins!" << endl;
            break;
        } else if (status == 0) {
            cout << "The game is a draw." << endl;
            break;
        }
        turnCount++;
    }
}

int main() {
    int replay = 1;
    do {
        playTicTacToe();
        cout << "Do you want to play another game (yes - 1 / no - 0)? ";
        cin >> replay;
    } while (replay != 0);

    return 0;
}
