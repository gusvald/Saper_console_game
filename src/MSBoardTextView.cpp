#include <iostream>
#include "MSBoardTextView.h"

MSBoardTextView::MSBoardTextView(MinesweeperBoard& board):board(board) {}

void MSBoardTextView::display() const {

    std::cout << "Game status: " << getGamestate() << std::endl;

    for (int i = 0; i < board.getBoardHeight(); i++) {
            for (int g = 0; g < board.getBoardWidth(); g++) {
                std::cout << "[" << board.getFieldInfo(g, i) << "]";
            }
            std::cout << std::endl ;
        }

    std::cout << std::endl;
}

std::string MSBoardTextView::getGamestate() const {
if(board.getGameState() == FINISHED_WIN)
    return "Victory";

if(board.getGameState() == FINISHED_LOSS)
    return "Defeated";

return "Game in progress";
}