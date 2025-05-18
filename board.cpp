#include "board.h"

bool Board::canPlaceRow(int col, int row, int ship) {
    if (row + ship > board_size) return false;
    for (int i = 0; i < ship; i++) {
        int x = row + i;
        int y = col;
        if (board[y][x] != EMPTY) return false;
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < board_size && ny >= 0 && ny < board_size) {
                    if (board[ny][nx] == SHIP) return false;
                }
            }
        }
    }
    return true;
}

bool Board::canPlaceCol(int col, int row, int ship) {
    if (col + ship > board_size) return false;
    for (int i = 0; i < ship; ++i) {
        int x = row;
        int y = col + i;
        if (board[y][x] != EMPTY) return false;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < board_size && ny >= 0 && ny < board_size) {
                    if (board[ny][nx] == SHIP) return false;
                }
            }
        }
    }
    return true;
}

void Board::putShip(int col, int row, int ship, bool horizontal) {
    for (int i = 0; i < ship; i++) {
        if (horizontal) {
            board[col][row + i] = SHIP;
        } else {
            board[col + i][row] = SHIP;
        }
    }
}

void Board::removeShip(int col, int row, int ship, bool horizontal) {
    for (int i = 0; i < ship; i++) {
        if (horizontal) {
            board[col][row + i] = EMPTY;
        } else {
            board[col + i][row] = EMPTY;
        }
    }
}

bool Board::placeShips(int shipIndex) {
    if (shipIndex >= ships_size) return true;
    int len = ships[shipIndex];
    for (int i = 0; i < board_size; ++i) {
        for (int j = 0; j < board_size; ++j) {
            if (canPlaceRow(i, j, len)) {
                putShip(i, j, len, true);
                if (placeShips(shipIndex + 1)) return true;
                removeShip(i, j, len, true);
            }
            if (canPlaceCol(i, j, len)) {
                putShip(i, j, len, false);
                if (placeShips(shipIndex + 1)) return true;
                removeShip(i, j, len, false);
            }
        }
    }
    return false;
}