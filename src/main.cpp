#include "MinesweeperBoard.h"
#include <cstdlib>
#include <ctime>

int main(){


    srand( time( nullptr ) );
    MinesweeperBoard playground(9,7,DEBUG);
    playground.debug_display();
    playground.getBoardWidth();
    playground.getBoardHeight();
    playground.getMineCount();
    playground.countMines(0,1);
    playground.toggleFlag(0, 1);
    playground.revealField(0, 1);
    playground.getGameState();
    playground.getFieldInfo(0,1);

  return 0;
}
