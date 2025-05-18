#ifndef BOARD_H
#define BOARD_H

const int board_size = 9;
const int ships_size = 10;

enum CellState { EMPTY = 0, SHIP = 1, BARRIER = 2 };

class Board {
public:
    bool canPlaceRow(int col, int row, int ship);
    bool canPlaceCol(int col, int row, int ship);
    void putShip(int col, int row, int ship, bool horizontal);
    void removeShip(int col, int row, int ship, bool horizontal);
    bool placeShips(int shipIndex);
    int board[board_size][board_size] = {{0}};
    int ships[ships_size] = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
};

#endif