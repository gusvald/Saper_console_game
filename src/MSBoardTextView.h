#ifndef TRY_V16_MSBOARDTEXTVIEW_H
#define TRY_V16_MSBOARDTEXTVIEW_H

#include "MinesweeperBoard.h"
#include <iostream>

class MSBoardTextView {
public:
        explicit MSBoardTextView(MinesweeperBoard& board);
        void display() const;
private:
    MinesweeperBoard& board;
    std::string getGamestate() const;
};


#endif //TRY_V16_MSBOARDTEXTVIEW_H
