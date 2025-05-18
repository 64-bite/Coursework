#include "utils.h"

void setBarrierRows() {
	for(int i = 0; i < board_size; i++) {
		for(int j = 0; j < board_size; j++) {
			if(white_rows[i] == ZERO && black_rows[i] == ZERO) {
			board[j][i] = BARRIER;
			} else if(white_rows[i] == EIGHT) {
				for(int k = 1; k < EIGHT; k++){
					board[k][i] = BARRIER;
			}
			} else if(white_rows[i] == SEVEN) { 
				for(int k = 2; k < SEVEN; k++){
					board[k][i] = BARRIER;
				}
			} else if(white_rows[i] == SIX) {
				for(int k = 3; k < EIGHT; k++) {
				board[k][i] = BARRIER;
				}
			}	
		}
	}
}
void setBarrierCols() {
	if(WhiteCols[i] == ZERO && BlackCols[i] == ZERO) {
		board[i][j] = BARRIER;
	} else if(WhiteCols[i] == EIGHT) {
		for(int k = 1; k < EIGHT; k++){
			board[i][k] = BARRIER;
		}
	} else if(WhiteCols[i] == SEVEN) { 
		for(int k = 2; k < SEVEN; k++){
			board[i][k] = BARRIER;
		}
	} else if(WhiteCols[i] == SIX) {
		for(int k = 3; k < EIGHT; k++) {
			board[i][k] = BARRIER;
		}
	}
}
void remove_barrier(){ 
	for(int i = 0; i < board_size; i++) {
		for(int j = 0; j < board_size; j++) {
			if(board[i][j] == BARRIER) {
				board[i][j] = EMPTY;
			}
		}
	}
}
