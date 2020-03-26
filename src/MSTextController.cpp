#include "MSTextController.h"
#include <iostream>


MSTextController::MSTextController(MinesweeperBoard& board, MSBoardTextView& view):board(board), view(view) {}

void MSTextController::play()
{
    int x,y,what_to_do;
    std::cout << "Welcome in Saper!" <<  std::endl;
    do{
        bool correct_value=true;
        bool correct_value1=true;
        view.display();
        std::cout << "Choose field (x,y): ";

        do{
            if(!correct_value)
                std::cout << "Incorect x,y try another:  ";
            std::cin >> y >> x;
            correct_value = false;
        }while(x < 0 || x >= board.getBoardWidth() || y < 0 || y >= board.getBoardHeight());



        std::cout << std::endl << "What will you do? " << std::endl << std::endl << "Choose 1. to reveal field. " << std::endl
        << "-------------------------------------------" << std::endl << "Choose 2. to set Flag on this field. "
        << std::endl << "-------------------------------------------" << std::endl << "Choose 3. to end game. "
        << std::endl << "-------------------------------------------" << std::endl;

        do {
            if(!correct_value1)
                std::cout << "Incorect option try another:  ";
            std::cin >> what_to_do;
                correct_value1 = false;
        }while(what_to_do !=1 && what_to_do !=2 && what_to_do !=3);

        if(what_to_do == 1)
            board.revealField(x,y);

        if(what_to_do == 2)
            board.toggleFlag(x,y);

        if(what_to_do == 3)
            break;

        view.display();

    } while(board.getGameState()==RUNNING);

    std::cout << "Game over" << std::endl;

}
