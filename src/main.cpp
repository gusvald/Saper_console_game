#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include <cstdlib>
#include <ctime>


int main()
{
    srand( time( nullptr ) );
    MinesweeperBoard board (9, 7, GameMode::DEBUG);
    MSBoardTextView view ( board );
    MSTextController ctrl ( board, view );
    ctrl.play();
}



/*
 *     MinesweeperBoard board (9, 7, GameMode::DEBUG);
    MSBoardTextView view ( board );
    view.display();
    board.revealField(0,5);
    view.display();
    board.revealField(0,0);
    view.display();
 */