#include <iostream>
#include "utils.h"
 /*----------------------------------------------------------------<Header>-
 Name: utils.cpp
 Title: Японський кросворд з човнами
 Group: ТВ-43
 Student: Матвієнко
 Written: 2025-05-22
 Revised: 2025-05-23
 Description: Файл по розстановці і видаленню бар'єрів
 TODO: Виправити помилку, не розставляються умови 
 ------------------------------------------------------------------</Header>-*/
  /* ---------------------------------------------------------------------[<]-
 Function: setBarrierRows()
 Synopsis: Метод, по виставленню бар'єрів в рядку
 ---------------------------------------------------------------------[>]-*/
void Utils::setBarrierRows(ShipsPlacement& placement) {
    for (int i = 0; i < g_board_size; i++) {
        for (int j = 0; j < g_board_size; j++) {
            if (placement.white_rows[i] == ZERO && placement.black_rows[i] == ZERO) {
                board.board[i][j] = BARRIER;
            }
        }
        if (placement.white_rows[i] == EIGHT) {
            for (int k = 1; k < EIGHT; k++) {
                board.board[i][k] = BARRIER;
            }
        } else if (placement.white_rows[i] == SEVEN) {
            for (int k = 2; k < SEVEN; k++) {
                board.board[i][k] = BARRIER;
            }
        } else if (placement.white_rows[i] == SIX) {
            for (int k = 3; k < EIGHT; k++) {
                board.board[i][k] = BARRIER;
            }
        }
    }
}
  /* ---------------------------------------------------------------------[<]-
 Function: setBarrierCols()
 Synopsis: Метод, по виставленню бар'єрів в стовпчику
 ---------------------------------------------------------------------[>]-*/
void Utils::setBarrierCols(ShipsPlacement& placement) {
    for (int i = 0; i < g_board_size; i++) {
        for (int j = 0; j < g_board_size; j++) {
            if (placement.white_cols[i] == ZERO && placement.black_cols[i] == ZERO) {
                board.board[j][i] = BARRIER;
            }
			if (placement.white_cols[i] == EIGHT) {
				for (int k = ONE; k < EIGHT; k++) {
					board.board[k][i] = BARRIER;
				}
			} else if (placement.white_cols[i] == SEVEN) {
				for (int k = TWO; k < SEVEN; k++) {
					board.board[k][i] = BARRIER;
				}
			} else if (placement.white_cols[i] == SIX) {
				for (int k = THREE; k < EIGHT; k++) {
					board.board[k][i] = BARRIER;
				}
			}
		}
	}    
}
  /* ---------------------------------------------------------------------[<]-
 Function: removeBarrier()
 Synopsis: Метод, по видаленню бар'єрів
 ---------------------------------------------------------------------[>]-*/
void Utils::removeBarrier() {	
    for (int i = 0; i < g_board_size; i++) {
        for (int j = 0; j < g_board_size; j++) {
            if (board.board[i][j] == BARRIER) {
                board.board[i][j] = EMPTY;
            }
        }
    }
}


