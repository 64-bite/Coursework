#ifndef UTILS_H 
#define UTILS_H

#include "board.h"
#include "shipsPlacement.h"
 /*----------------------------------------------------------------<Header>-
 Name: utils.h
 Title: Японський кросворд з човнами
 Group: ТВ-43
 Student: Матвієнко
 Written: 2025-05-22
 Revised: 2025-05-23
 Description: Хеш функція по роботі з барьєрами
 ------------------------------------------------------------------</Header>-*/
enum BarrierNum { ZERO = 0, ONE = 1, TWO = 2, THREE = 3, SIX = 6, SEVEN = 7, EIGHT = 8 };//Умови для барє'рів

class Utils {
    Board board;
public:
    void setBarrierRows(ShipsPlacement& placement);
    void setBarrierCols(ShipsPlacement& placement);
    void removeBarrier();
};

#endif
