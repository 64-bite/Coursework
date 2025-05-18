#include "ships_placement.h"
#include <algorithm>

ShipsPlacement::ShipsPlacement(const std::vector<int>& wrows, const std::vector<int>& brows, 
                               const std::vector<int>& wcols, const std::vector<int>& bcols) {
    for (int i = 0; i < board_size; ++i) {
        white_rows[i] = wrows[i];
        black_rows[i] = brows[i];
        white_cols[i] = wcols[i];
        black_cols[i] = bcols[i];
    }
}

ShipsPlacement::ShipsPlacement() {
    int wr[board_size] = {4, 0, 3, 7, 4, 0, 8, 3, 8};
    int br[board_size] = {3, 0, 4, 0, 2, 0, 0, 0, 0};
    int wc[board_size] = {3, 7, 3, 4, 6, 6, 4, 8, 2};
    int bc[board_size] = {2, 0, 0, 0, 0, 0, 0, 0, 3};
    for (int i = 0; i < board_size; ++i) {
        white_rows[i] = wr[i];
        black_rows[i] = br[i];
        white_cols[i] = wc[i];
        black_cols[i] = bc[i];
    }
}

int ShipsPlacement::longestSequence(int index, bool horizontal, bool occupied) {
    int count = 0, result = 0;
    for (int i = 0; i < board_size; i++) {
        int value = horizontal ? board.board[index][i] : board.board[i][index];
        if ((occupied && value == SHIP) || (!occupied && value == EMPTY)) {
            count++;
            result = std::max(result, count);
        } else {
            count = 0;
        }
    }
    return result;
}

bool ShipsPlacement::checkRowsAndCols() {
    for (int i = 0; i < board_size; i++) {
        rows[i] = true;
        cols[i] = true;
    }
    return true;
}
