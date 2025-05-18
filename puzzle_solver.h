#ifndef PUZZLE_SOLVER_H
#define PUZZLE_SOLVER_H

#include "ships_placement.h"
#include "utils.h"
#include <string>
class PuzzleSolver {
public:
    PuzzleSolver(const ShipsPlacement& placement);
    bool solve(int shipIndex = 0);
    bool repairBoard();
    void printConsoleFile(const std::string& filename);
private:
    ShipsPlacement placement;
    Utils utils;
};

#endif
