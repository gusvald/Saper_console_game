#ifndef TRY_V16_MSTEXTCONTROLLER_H
#define TRY_V16_MSTEXTCONTROLLER_H

#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"
#include <iostream>

class MSTextController {
public:
    MSTextController(MinesweeperBoard& board, MSBoardTextView& view);
    void play();
private:
    MinesweeperBoard& board;
    MSBoardTextView& view;
};



#endif //TRY_V16_MSTEXTCONTROLLER_H
