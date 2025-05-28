#ifndef BOARD_H
#define BOARD_H
 /*----------------------------------------------------------------<Header>-
 Name: board.h
 Title: Японський кросворд з човнами
 Group: ТВ-43
 Student: Матвієнко
 Written: 2025-05-22
 Revised: 2025-05-23
 Description: Хеш функція оголошує функції по розстановці човнів
 ------------------------------------------------------------------</Header>-*/
const int g_board_size = 9;//Розмір рядка і колонки 
const int g_ships_size = 10;//Кількість човнів

enum CellState { EMPTY = 0, SHIP = 1, BARRIER = 2 };//Константні змінні, що позначають статус кожної клітинки

class Board {
public:
	int board[g_board_size][g_board_size] = {{0}};//дошка
    int ships[g_ships_size] = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};//човни
public:
    bool canPlaceRow(int col, int row, int ship);
    bool canPlaceCol(int col, int row, int ship);
    void putShip(int col, int row, int ship, bool horizontal);
    void removeShip(int col, int row, int ship, bool horizontal);
    bool placeShips(int shipIndex);
    
};

#endif

