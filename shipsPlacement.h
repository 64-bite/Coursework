#ifndef SHIPS_PLACEMENT_H
#define SHIPS_PLACEMENT_H

#include <vector>
#include "board.h"
 /*----------------------------------------------------------------<Header>-
 Name: shipsPlacement.h
 Title: Японський кросворд з човнами
 Group: ТВ-43
 Student: Матвієнко
 Written: 2025-05-22
 Revised: 2025-05-23
 Description: Хеш функція, що реалізує мтоди по роботі з умовами по краях дошки  
 ------------------------------------------------------------------</Header>-*/
class ShipsPlacement {
public:
/*Задіяти rows, cols в коді*/
    bool rows[board_size] = {false};//поле, по зберіганню відповідності дошки до умов по рядкам 
    bool cols[board_size] = {false};//поле, по зберіганню відповідності дошки до умов по стовпцям
	int white_rows[board_size];//Умова для білих стовпців
    int black_rows[board_size];//Умова для чорних стовпців
    int white_cols[board_size];//Умова для білих рядків
    int black_cols[board_size];//Умова для чорних рядків
public:
    ShipsPlacement(const std::vector<int>& wrows, const std::vector<int>& brows,
                   const std::vector<int>& wcols, const std::vector<int>& bcols);
    ShipsPlacement();
	Board board;
    int longest(int index, bool horizontal, bool occupied);
    bool checkRows();
	bool checkCols();
};

#endif
