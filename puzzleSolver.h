#ifndef PUZZLE_SOLVER_H
#define PUZZLE_SOLVER_H
#include <string>
#include "shipsPlacement.h"
#include "utils.h"
#include "board.h"
 /*----------------------------------------------------------------<Header>-
 Name: puzzleSolver.h
 Title: Японський кросворд з човнами
 Group: ТВ-43
 Student: Матвієнко
 Written: 2025-05-22
 Revised: 2025-05-23
 Description: Хеш функція оголошує функції по вирішенню головоломки і виводу виконаної головоломки в файл
 ------------------------------------------------------------------</Header>-*/
class PuzzleSolver {
	ShipsPlacement placement;
    Utils utils;
	Board board;
public:
    PuzzleSolver(const ShipsPlacement& placement);
    bool solve(int shipIndex = 0);
    bool repairBoard();
    void printConsoleFile(const std::string& filename);
};

#endif
