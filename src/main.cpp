#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include <cstdlib>
#include <ctime>


int main() {
    srand(time(nullptr));
    MinesweeperBoard board(3, 3, GameMode::HARD);
    MSBoardTextView view(board);
    MSTextController ctrl(board, view);
    ctrl.play();
}



