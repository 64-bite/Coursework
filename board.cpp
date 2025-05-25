#include "board.h"
 /*----------------------------------------------------------------<Header>-
 Name: board.h
 Title: Японський кросворд з човнами
 Group: ТВ-43
 Student: Матвієнко
 Written: 2025-05-22
 Revised: 2025-05-23
 Description: Файл який реалізує методи по роботі з човнами 
 ------------------------------------------------------------------</Header>-*/
 /* ---------------------------------------------------------------------[<]-
 Function: canPlaceRow()
 Synopsis: Перевірка, чи можна поставити човен певного розміру в рядок
 ---------------------------------------------------------------------[>]-*/
bool Board::canPlaceRow(int col, int row, int ship) {
    if (row + ship >g_board_size) return false;
    for (int i = 0; i < ship; i++) {
        int x = row + i;
        int y = col;
        if (board[y][x] != EMPTY) return false;
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < g_board_size && ny >= 0 && ny < g_board_size) {
                    if (board[ny][nx] == SHIP || board[ny][nx] == BARRIER) return false;
                }
            }
        }
    }
    return true;
}
 /* ---------------------------------------------------------------------[<]-
 Function: canPlaceCol()
 Synopsis: Перевірка, чи можна поставити човен певного розміру в стовпчику
 ---------------------------------------------------------------------[>]-*/
bool Board::canPlaceCol(int col, int row, int ship) {
    if (col + ship > g_board_size) return false;
    for (int i = 0; i < ship; i++) {
        int x = row;
        int y = col + i;
        if (board[y][x] != EMPTY) return false;
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < g_board_size && ny >= 0 && ny < g_board_size) {
                    if (board[ny][nx] == SHIP  || board[ny][nx] == BARRIER) return false;
                }
            }
        }
    }
    return true;
}
 /* ---------------------------------------------------------------------[<]-
 Function: putShip()
 Synopsis: Метод, який ставить човен на дошку
 ---------------------------------------------------------------------[>]-*/
void Board::putShip(int col, int row, int ship, bool horizontal) {
    for (int i = 0; i < ship; i++) {
        if (horizontal) {
            board[col][row + i] = SHIP;
        } else {
            board[col + i][row] = SHIP;
        }
    }
}
 /* ---------------------------------------------------------------------[<]-
 Function: removeShip()
 Synopsis: Метод, який видаляє човен з дошки
 ---------------------------------------------------------------------[>]-*/
void Board::removeShip(int col, int row, int ship, bool horizontal) {
    for (int i = 0; i < ship; i++) {
        if (horizontal) {
            board[col][row + i] = EMPTY;
        } else {
            board[col + i][row] = EMPTY;
        }
    }
}
 /* ---------------------------------------------------------------------[<]-
 Function: placeShips()
 Synopsis: Метод, який виставляє човни на дошку
 ---------------------------------------------------------------------[>]-*/
bool Board::placeShips(int shipIndex) {
    if (shipIndex > g_ships_size) return false;
    int len = ships[shipIndex];
    for (int i = 0; i < g_board_size; i++) {
        for (int j = 0; j < g_board_size; j++) {
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
    return true;
}
