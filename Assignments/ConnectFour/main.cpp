#include "main.h"

/*
    2 players (Red & Yellow)
    Board is 6 rows x 7 columns
    Players alternate turns dropping pieces into column
    The piece falls to the lowest empty slot in that column
    First player to get 4 in a row (Horizontal, vertical or diagonal) wins
    If the board fills with no winner -> draw
*/

int main() {
    std::array<std::array<char, col>, row> board{};

    char currentPlayer = 'R';

    initializeBoard(board);
    printBoard(board);

    while (true) {
        // ask player for input
        int column;
        std::cout << "Player " << currentPlayer << ", drop a disk at column (0-6): ";
        std::cin >> column;

        if (column < 0 || column >= col) {
            std::cout << "Invalid choice. Try again. \n";
            continue;
        } 

        // try to drop piece
        int placedRow = dropPiece(board, column, currentPlayer);

        if (placedRow == -1) {
            std::cout << "Column full. Try again. \n";
            continue;
        }

        if (isBoardFull(board)) {
            std::cout << "Draw. Game Over\n";
            break;
        }

        printBoard(board);

        if (checkScore(board, placedRow, column, currentPlayer)) {
            std::cout << "Player " << currentPlayer << " wins\n";
            break;
        }

        // switch player
        currentPlayer = (currentPlayer == 'R') ? 'Y' : 'R';
    }
}

void initializeBoard(std::array<std::array<char, col>, row>& board) {
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            board[r][c] = ' '; // empty cell
        }
    }
}

void printBoard(const std::array<std::array<char, col>, row>& board) {
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            std::cout << "|" << board[r][c];
        }

        std::cout << '\n';
    }
}

int dropPiece(std::array<std::array<char, col>, row>& board, int c, char player) {
    for (int i = row - 1; i >= 0; i--) { // scan from bottom row up
        if (board[i][c] == ' ') {      // if cell is empty
            board[i][c] = player;      // place piece 

            return i;                
        }
    }

    return -1;                        // occupied cell
}

bool checkScore(std::array<std::array<char, col>, row>& board, int r, int c, char player) {
    if (checkHorizontal(board, r, c, player)) return true;
    if (checkVertical(board, r, c, player)) return true;
    if (checkDiagonal(board, r, c, player)) return true;
   
    return false;
}

bool checkHorizontal(const std::array<std::array<char, col>, row>& board, int r, int c, char player) {
    int count = 1;

    // check left
    int colCheck = c - 1; // piece to the left
    while (colCheck >= 0 && board[r][colCheck] == player) {
        count++; // matching piece, add to total
        colCheck--; // check next piece to the left
    }

    // check right
    colCheck = c + 1; 
    while (colCheck < col && board[r][colCheck] == player) {
        count++;
        colCheck++;
    }

    return count >= 4;
}

bool checkVertical(const std::array<std::array<char, col>, row>& board, int r, int c, char player) {
    int count = 1;

    // check above
    int rowCheck = r - 1; // piece above
    while (rowCheck >= 0 && board[rowCheck][c] == player) {
        count++; // matching piece, add to total
        rowCheck--; // check next piece above
    }

    // check below
    rowCheck = r + 1; 
    while (rowCheck < row && board[rowCheck][c] == player) {
        count++;
        rowCheck++;
    }

    return count >= 4;
}

bool checkDiagonal(const std::array<std::array<char, col>, row>& board, int r, int c, char player) {
    int count = 1;

    // up-right / down-left check
    int rowCheck = r - 1;
    int colCheck = c + 1;
    while (rowCheck >= 0 && colCheck < col &&
           board[rowCheck][colCheck] == player) {
        count++;
        rowCheck--;
        colCheck++;
    }

    rowCheck = r + 1;
    colCheck = c - 1;
    while (rowCheck < row && colCheck >= 0 &&
           board[rowCheck][colCheck] == player) {
        count++;
        rowCheck++;
        colCheck--;
    }

    return count >= 4;

    // up-left / down-right check
    count = 1;

    rowCheck = r - 1;
    colCheck = c - 1;
    while (rowCheck >= 0 && colCheck >= 0 &&
           board[rowCheck][colCheck] == player) {
        count++;
        rowCheck--;
        colCheck--;
    }

    rowCheck = r + 1;
    colCheck = c + 1;
    while (rowCheck < row && colCheck < col &&
           board[rowCheck][colCheck] == player) {
        count++;
        rowCheck++;
        colCheck++;
    }

    return count >= 4;
}

bool isBoardFull(const std::array<std::array<char, col>, row>& board) {
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            if (board[r][c] == ' ') {
                // cell empty exists
                return false;
            }
        }
    }

    return true;
}
