#include <iostream>
#include <fstream>
#include <string>
#include "puzzleSolver.h"
 /*----------------------------------------------------------------<Header>-
 Name: puzzleSolver.cpp
 Title: Японський кросворд з човнами
 Group: ТВ-43
 Student: Матвієнко
 Written: 2025-05-22
 Revised: 2025-05-23
 Description: Файл містить клас по вирішенню головоломки solve(), метод виправлення розташування човнів repairBoard(), метод виводу в файл printConsoleFile
 ------------------------------------------------------------------</Header>-*/
using namespace std;
/* ---------------------------------------------------------------------[<]-
 Function: PuzzleSolver()
 Synopsis: Конструктор
 ---------------------------------------------------------------------[>]-*/
PuzzleSolver::PuzzleSolver(const ShipsPlacement& p) : placement(p) {}
/* ---------------------------------------------------------------------[<]-
 Function: solve()
 Synopsis: Вирішення головоломки
 ---------------------------------------------------------------------[>]-*/
bool PuzzleSolver::solve(int shipIndex) {
    utils.setBarrierRows(placement);
    utils.setBarrierCols(placement);
    bool success = placement.board.placeShips(shipIndex);
    if (success && placement.checkRows() && placement.checkRows()) {
		return true;
    }
    return false;
}
/* ---------------------------------------------------------------------[<]-
 Function: repairBoard()
 Synopsis: Виправлення помилок на дошці
 ---------------------------------------------------------------------[>]-*/
bool PuzzleSolver::repairBoard() {
    return true;
}
/* ---------------------------------------------------------------------[<]-
 Function: printConsoleFile()
 Synopsis: Вивід вирішеної головоломки в консоль та у файл
 ---------------------------------------------------------------------[>]-*/
void PuzzleSolver::printConsoleFile(const string& filename) {
    ofstream out(filename);
    if (!out) {
        cout << "Can’t open file!\n";
        return;
    }
	cout << "Вирішенна головоломка: \n";
	cout << "   ";
    out << "   ";
    for (int i = 0; i < board_size; ++i) {
		cout << placement.white_rows[i] << ' ';
		out << placement.white_rows[i] << ' ';
	}
    cout << '\n';
	out << '\n';
    for (int i = 0; i < board_size; i++) {
        cout << placement.white_cols[i] << "  ";
		out << placement.white_cols[i] << "  ";
        for (int j = 0; j < board_size; j++) {
            cout << placement.board.board[i][j] << ' ';
			out << placement.board.board[i][j] << ' ';
        }
        cout << placement.black_cols[i] << '\n';
		out << placement.black_cols[i] << '\n';
    }
	cout << "   ";
    out << "   ";
    for (int i = 0; i < board_size; ++i) {
		cout << placement.black_rows[i] << ' ';
		out << placement.black_rows[i] << ' ';
	}
	cout << '\n';
    out << '\n';
    out.close();
}
