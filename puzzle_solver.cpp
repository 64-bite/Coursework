#include "puzzle_solver.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

PuzzleSolver::PuzzleSolver(const ShipsPlacement& p) : placement(p) {}

bool PuzzleSolver::solve(int shipIndex) {
    utils.setBarrierRows(placement);
    utils.setBarrierCols(placement);
    bool success = placement.board.placeShips(shipIndex);
    utils.removeBarrier();
    if (success && placement.checkRowsAndCols()) {
        return true;
    }
    return false;
}

bool PuzzleSolver::repairBoard() {
    return true;
}

void PuzzleSolver::printConsoleFile(const string& filename) {
    ofstream out(filename);
    if (!out) {
        cout << "Can’t open file!\n";
        return;
    }

    out << "   ";
    for (int i = 0; i < board_size; ++i) out << placement.white_rows[i] << ' ';
    out << '\n';

    for (int i = 0; i < board_size; ++i) {
        out << placement.white_cols[i] << "  ";
        for (int j = 0; j < board_size; ++j) {
            out << placement.board.board[i][j] << ' ';
        }
        out << placement.black_cols[i] << '\n';
    }

    out << "   ";
    for (int i = 0; i < board_size; ++i) out << placement.black_rows[i] << ' ';
    out << '\n';
}
