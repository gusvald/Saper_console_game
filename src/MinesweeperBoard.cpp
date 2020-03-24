#include <iostream>
#include "MinesweeperBoard.h"

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode):
width(width), height(height), mode(mode), state(RUNNING)
{

    this->width = width;
    this->height = height;


    if (width >= 100 || height >= 100 || width < 0 || height < 0) {
        width = 10;
        height = 10;
    }


    if (mode == DEBUG) {
        MineQuantity = 18;
        for (int g = 0; g < height; g++) {
            for (int i = 0; i < width; i++) {
                if (i == g)
                    board[g][i].hasMine = true;
                if (g == 0)
                    board[g][i].hasMine = true;
                if (i == 0 && g % 2 == 0)
                    board[g][i].hasMine = true;
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
            if (!board[y][x].hasMine) {
                board[y][x].hasMine = true;
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


void MinesweeperBoard::debug_display() const
{
    for (int i = 0; i < width; i++) {
        for (int g = 0; g < height; g++) {
            this->display_Field(board[g][i]);
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
    if (this->isRevealed(x, y) && !board[y][x].hasMine) {
        for (int i = (x + 1); i > (x - 2); i--) {
            for (int g = (y + 1); g > (y - 2); g--) {
                if (i >= 0 && g >= 0) {
                    if (board[g][i].hasMine) {
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
        return board[y][x].isRevealed;
    }
    return false;
}


bool MinesweeperBoard::hasFlag(int x, int y) const {
    return !(this->isRevealed(x, y) || !board[y][x].hasFlag);
}

void MinesweeperBoard::toggleFlag(int x, int y) {
    if (!this->isRevealed(x, y)) {
        board[y][x].hasFlag = true;
        if (this->FIRSTMOVE)
            this->FIRSTMOVE = false;
    } else if (this->isRevealed(x, y) || this->state != RUNNING)
        return;
}

void MinesweeperBoard::revealField(int x, int y) {
    if (this->isRevealed(x, y) || this->hasFlag(x, y))
        return;
    if (!this->isRevealed(x, y) || !board[y][x].hasMine) {
        board[y][x].isRevealed = true;
        if (this->FIRSTMOVE)
            this->FIRSTMOVE = false;
    }

    if (!this->isRevealed(x, y) || board[y][x].hasMine || !this->FIRSTMOVE) {
        board[y][x].isRevealed = true;
        this->state = FINISHED_LOSS;
    }

    if (!this->isRevealed(x, y) || board[y][x].hasMine || this->FIRSTMOVE || mode != DEBUG) {
        board[y][x].isRevealed = true;
        board[y][x].hasMine = false;
        board[rand() % width][rand() % height].hasMine = true;
        board[y][x].isRevealed = true;
    }
    if (this->WinCondition())
    { this-> state = FINISHED_WIN; }
}


GameState MinesweeperBoard::getGameState() const
{
    return this->state;
}


bool MinesweeperBoard::WinCondition() const {
    int flags = 0;
    int mines = 0;
    for (int i = 0; i < width; i++) {
        for (int g = 0; g < height; g++) {
            if (board[g][i].hasMine && board[g][i].hasFlag) {
                flags++;
            }
            if (board[g][i].hasMine && !board[g][i].isRevealed) {
                mines++;
            }

        }
    }

    return flags == this->getMineCount() || mines == this->getMineCount();

}


char MinesweeperBoard::getFieldInfo(int x, int y) const { 



    if (!isOutRange(x, y)) {

    if (!board[y][x].isRevealed && board[y][x].hasFlag)
        return 'F';

    if (!board[y][x].isRevealed && !board[y][x].hasFlag)
        return '_';

    if (board[y][x].isRevealed && board[y][x].hasMine)
        return 'x';

    if (board[y][x].isRevealed && this->countMines(x, y) == 0)
        return ' ';

    if (board[y][x].isRevealed && this->countMines(x, y) != 0) {
        return countMines(x, y) + '0';
    }
}
    return '#';
}

