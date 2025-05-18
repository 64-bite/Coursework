#include "utils.h"

void Utils::setBarrierRows(ShipsPlacement& placement) {
    for (int i = 0; i < board_size; i++) {
        if (placement.white_rows[i] == ZERO && placement.black_rows[i] == ZERO) {
            for (int j = 0; j < board_size; j++)
                placement.board.board[i][j] = BARRIER;
        }
    }
}

void Utils::setBarrierCols(ShipsPlacement& placement) {
    for (int i = 0; i < board_size; i++) {
        if (placement.white_cols[i] == ZERO && placement.black_cols[i] == ZERO) {
            for (int j = 0; j < board_size; j++)
                placement.board.board[j][i] = BARRIER;
        }
    }
}

void Utils::removeBarrier(ShipsPlacement& placement) {
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            if (placement.board.board[i][j] == BARRIER)
                placement.board.board[i][j] = EMPTY;
        }
    }
}
