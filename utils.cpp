#include "utils.h"

void Utils::setBarrierRows(ShipsPlacement& placement) {
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            if (placement.white_rows[i] == ZERO && placement.black_rows[i] == ZERO) {
                b.board[i][j] = BARRIER;
            }
        }

        if (placement.white_rows[i] == EIGHT) {
            for (int k = 1; k < EIGHT; k++) {
                b.board[i][k] = BARRIER;
            }
        } else if (placement.white_rows[i] == SEVEN) {
            for (int k = 2; k < SEVEN; k++) {
                b.board[i][k] = BARRIER;
            }
        } else if (placement.white_rows[i] == SIX) {
            for (int k = 3; k < EIGHT; k++) {
                b.board[i][k] = BARRIER;
            }
        }
    }
}

void Utils::setBarrierCols(ShipsPlacement& placement) {
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            if (placement.white_cols[i] == ZERO && placement.black_cols[i] == ZERO) {
                b.board[j][i] = BARRIER;
            }
        }

        if (placement.white_cols[i] == EIGHT) {
            for (int k = 1; k < EIGHT; k++) {
                b.board[k][i] = BARRIER;
            }
        } else if (placement.white_cols[i] == SEVEN) {
            for (int k = 2; k < SEVEN; k++) {
                b.board[k][i] = BARRIER;
            }
        } else if (placement.white_cols[i] == SIX) {
            for (int k = 3; k < EIGHT; k++) {
                b.board[k][i] = BARRIER;
            }
        }
    }
}

void Utils::removeBarrier() {
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            if (b.board[i][j] == BARRIER) {
                b.board[i][j] = EMPTY;
            }
        }
    }
}
