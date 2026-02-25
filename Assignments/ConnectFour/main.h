#include <iostream>
#include <array>

const int row = 6;
const int col = 7;

void initializeBoard(std::array<std::array<char, col>, row>& board);
void printBoard(const std::array<std::array<char, col>, row>& board);
int dropPiece(std::array<std::array<char, col>, row>& board, int c, char player);
bool isBoardFull(const std::array<std::array<char, col>, row>& board);
bool checkHorizontal(const std::array<std::array<char, col>, row>& board, int r, int c, char player);
bool checkVertical(const std::array<std::array<char, col>, row>& board, int r, int c, char player);
bool checkDiagonal(const std::array<std::array<char, col>, row>& board, int r, int c, char player);
bool checkScore(std::array<std::array<char, col>, row>& board, int r, int c, char player);