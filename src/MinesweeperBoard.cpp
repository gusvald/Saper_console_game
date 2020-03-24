#include <iostream>
#include "MinesweeperBoard.h"

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode)  {  // zainicjuj liste startowa

    this->width = width;
    this->height = height;


    if (width >= 100 || height >= 100 || width < 0 || height < 0) {
        width = 10;
        height = 10;
    }


    if (mode == DEBUG) {
        MineQuantity = 18;
        for (int i = 0; i < height; i++) {
            for (int g = 0; g < width; g++) {
                if (i == g)
                    board[i][g].hasMine = true;
                if (i == 0)
                    board[i][g].hasMine = true;
                if (g == 0 && i % 2 == 0)
                    board[i][g].hasMine = true;
            }
        }
    }

    if (mode != DEBUG) {
        MineQuantity = (width * height * mode) / 100;
        int mines = 0;
        while (mines < MineQuantity) {
            int x, y;
            x = rand() % width;
            y = rand() % height;
            if (!board[x][y].hasMine) {
                board[x][y].hasMine = true;
                mines = mines + 1;
            }
        }

    }

}


void MinesweeperBoard::display_Field(Field field) const {
    std::cout << "[";
    if (field.hasMine) {
        std::cout << "M";
    } else {
        std::cout << ".";
    }
    if (field.isRevealed) {
        std::cout << "o";
    } else {
        std::cout << ".";
    }
    if (field.hasFlag) {
        std::cout << "f";
    } else {
        std::cout << ".";
    }
    std::cout << "]";
}


void MinesweeperBoard::debug_display() const // referencja na field i popraw w headearze
{
    for (int i = 0; i < height; i++) {
        for (int g = 0; g < width; g++) {
            this->display_Field(board[i][g]);
        }
        std::cout << std::endl;
    }
}

bool MinesweeperBoard::isOutRange(int x, int y) const {

    return (x < 0 || x >= this->width || y < 0 || y >= this->height);


}

int MinesweeperBoard::getBoardWidth() const {
    return this->width;
}

int MinesweeperBoard::getBoardHeight() const {
    return this->height;
}

int MinesweeperBoard::getMineCount() const {
    return this->MineQuantity;
}

int MinesweeperBoard::countMines(int x, int y) const {
    int mines = 0;
    if (this->isRevealed(x, y) && !board[x][y].hasMine) {
        for (int i = (x + 1); i > (x - 2); i--) {
            for (int g = (y + 1); g > (y - 2); g--) {
                if (i >= 0 && g >= 0) {
                    if (board[i][g].hasMine) {
                        mines += 1;
                    }
                }
            }
        }
        return mines;
    }

    return -1;


}

bool MinesweeperBoard::isRevealed(int x, int y) const {
    if (!isOutRange(x, y)) {
        return board[x][y].isRevealed;
    }
    return false;
}


bool MinesweeperBoard::hasFlag(int x, int y) const { //zamień warunki
    if (board[x][y].hasFlag)
        return true;
    else if (this->isRevealed(x, y) || !board[x][y].hasFlag)
        return false;
    return false;
}

void MinesweeperBoard::toggleFlag(int x, int y) {
    if (!this->isRevealed(x, y)) {
        board[x][y].hasFlag = true;
        if (this->FIRSTMOVE)
            this->FIRSTMOVE = false;
    } else if (this->isRevealed(x, y) || this->state == FINISHED_LOSS || this->state == FINISHED_WIN)//=!RUNNIG
        return;
}

void MinesweeperBoard::revealField(int x, int y) {
    if (this->isRevealed(x, y) || this->hasFlag(x, y))
        return;
    if (!this->isRevealed(x, y) || !board[x][y].hasMine) {
        board[x][y].isRevealed = true;
        if (this->FIRSTMOVE)
            this->FIRSTMOVE = false;
    }

    if (!this->isRevealed(x, y) || board[x][y].hasMine || !this->FIRSTMOVE) {
        board[x][y].isRevealed = true;
        this->state = FINISHED_LOSS;
    }

    if (!this->isRevealed(x, y) || board[x][y].hasMine || this->FIRSTMOVE || mode != DEBUG) {
        board[x][y].isRevealed = true;
        board[x][y].hasMine = false;
        board[rand() % width][rand() % height].hasMine = true;
        board[x][y].isRevealed = true;
    }
    //win condition
}


GameState MinesweeperBoard::getGameState() const { // z tego zrób getter
    if (this->WinCondition()) { return FINISHED_WIN; }
    else if (this->state == RUNNING)
        return RUNNING;
    if (this->state == FINISHED_LOSS)
        return FINISHED_LOSS;
    return RUNNING;

}


bool MinesweeperBoard::WinCondition() const {
    int flags = 0;
    int mines = 0;
    for (int i = 0; i < width; i++) {
        for (int g = 0; g < height; g++) {
            if (board[i][g].hasMine && board[i][g].hasFlag) {
                flags++;
            }
            if (board[i][g].hasMine && !board[i][g].isRevealed) {
                mines++;
            }

        }
    }

    return flags == this->getMineCount() || mines == this->getMineCount();

}


char MinesweeperBoard::getFieldInfo(int x, int y) const { // do przebudowania w ifa wszystko w out of range potem zwroc #
    if (x < 0 || y < 0 || x >= width || y >= height)
        return '#';

    if (!board[x][y].isRevealed && board[x][y].hasFlag)
        return 'F';

    if (!board[x][y].isRevealed && !board[x][y].hasFlag)
        return '_';

    if (board[x][y].isRevealed && board[x][y].hasMine)
        return 'x';

    if (board[x][y].isRevealed && this->countMines(x, y) == 0)
        return ' ';

    if (board[x][y].isRevealed && this->countMines(x, y) != 0) {
        return countMines(x, y) + '0';
    }
    return '0';
}

