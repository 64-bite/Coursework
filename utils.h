#ifndef UTILS_H
#define UTILS_H

#include "board.h"
#include "ships_placement.h"

enum BarrierNum { SIX = 6, SEVEN = 7, EIGHT = 8, ZERO = 0 };

class Utils {
public:
    void setBarrierRows(ShipsPlacement& placement);
    void setBarrierCols(ShipsPlacement& placement);
    void removeBarrier(ShipsPlacement& placement);
};

#endif
