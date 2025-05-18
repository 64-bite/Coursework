#ifndef SHIPS_PLACEMENT_H
#define SHIPS_PLACEMENT_H

#include <vector>
#include "board.h"

class ShipsPlacement {
public:
    ShipsPlacement(const std::vector<int>& wrows, const std::vector<int>& brows,
                   const std::vector<int>& wcols, const std::vector<int>& bcols);
    ShipsPlacement();
    int longestSequence(int index, bool horizontal, bool occupied);
    bool checkRowsAndCols();

    int white_rows[board_size];
    int black_rows[board_size];
    int white_cols[board_size];
    int black_cols[board_size];
    Board board;

private:
    bool rows[board_size] = {false};
    bool cols[board_size] = {false};
};

#endif
