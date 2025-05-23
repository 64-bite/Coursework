#include <algorithm>
#include "shipsPlacement.h"

/*----------------------------------------------------------------<Header>-
 Name: shipsPlacement.cpp
 Title: Японський кросворд з човнами
 Group: ТВ-43
 Student: Матвієнко
 Written: 2025-05-22
 Revised: 2025-05-23
 Description:Функція по ініціалізації умов головоломки і по перевірці дошки на відповідність до цих умов 
 ------------------------------------------------------------------</Header>-*/
 /* ---------------------------------------------------------------------[<]-
 Function: ShipsPlacement()
 Synopsis: Конструктор, який ініціалізує умови введені користувачем
 ---------------------------------------------------------------------[>]-*/
ShipsPlacement::ShipsPlacement(const std::vector<int>& wrows, const std::vector<int>& brows, 
                               const std::vector<int>& wcols, const std::vector<int>& bcols) {
    for (int i = 0; i < board_size; i++) {
        white_rows[i] = wrows[i];
        black_rows[i] = brows[i];
        white_cols[i] = wcols[i];
        black_cols[i] = bcols[i];
    }
}
   /* ---------------------------------------------------------------------[<]-
 Function: ShipsPlacement()
 Synopsis: Конструктор, який ініціалізує умови введені в програмі
 ---------------------------------------------------------------------[>]-*/
ShipsPlacement::ShipsPlacement() {
    int wr[board_size] = {4, 0, 3, 7, 4, 0, 8, 3, 8};
    int br[board_size] = {3, 0, 4, 0, 2, 0, 0, 0, 0};
    int wc[board_size] = {3, 8, 3, 4, 6, 6, 4, 8, 2};
    int bc[board_size] = {2, 0, 0, 0, 0, 0, 0, 0, 3};
    for (int i = 0; i < board_size; i++) {
        white_rows[i] = wr[i];
        black_rows[i] = br[i];
        white_cols[i] = wc[i];
        black_cols[i] = bc[i];
    }
}
 /* ---------------------------------------------------------------------[<]-
 Function: longest()
 Synopsis: Метод, по підрахунку найбільшої послідовності білих або чорних клітинок
 ---------------------------------------------------------------------[>]-*/
int ShipsPlacement::longest(int index, bool horizontal, bool occupied) {
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
 /* ---------------------------------------------------------------------[<]-
 Function: checkRows()
 Synopsis: Метод, по перевірці умов рядків
 ---------------------------------------------------------------------[>]-*/
bool ShipsPlacement::checkRows() {
    for(int i = 0; i < board_size; i++) {
		if(longest(true,i,false) == 9 && white_cols[i] == 0 && black_cols[i] == 0) {
			rows[i] = true;
		} else if(white_cols[i] == 0 && longest(true,i,true) == black_cols[i]) {
			rows[i] = true;
		} else if(black_cols[i] == 0 && longest(true,i,false) == white_cols[i] ) {
			rows[i] = true;
		} else if(black_cols[i] != 0 && white_cols[i] != 0 && longest(true,i,false) == white_cols[i] && longest(true,i,true) == black_cols[i]){
			rows[i] = true;
		} else { 
			rows[i] = false;
		}
	}
    return true;
}
 /* ---------------------------------------------------------------------[<]-
 Function: checkCols()
 Synopsis: Метод, по перевірці умов стовпців
 ---------------------------------------------------------------------[>]-*/
bool ShipsPlacement::checkCols() {
	for(int i = 0; i < board_size; i++) {	
		if(longest(false,i,false) == 9 && white_rows[i] == 0 && black_rows[i] == 0) {
			cols[i] = true;
		} else if(white_rows[i] == 0 && longest(false,i,true) == black_rows[i]) {
			cols[i] = true;
		} else if(black_rows[i] == 0 && longest(false,i,false) == white_rows[i] ) {
			cols[i] = true;
		} else if(black_rows[i] != 0 && white_rows[i] != 0 && longest(false,i,false) == white_rows[i] && longest(false,i,true) == black_rows[i]){
			cols[i] = true;
		} else { 
			cols[i] = false;
		}
	}
	return true;
}
