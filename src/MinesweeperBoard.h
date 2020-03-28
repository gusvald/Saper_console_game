#ifndef TRY4_MINESWEEPERBOARD_H
#define TRY4_MINESWEEPERBOARD_H

struct Field
{
    bool hasMine = false;
    bool hasFlag = false;
    bool isRevealed = false;
};

enum GameMode  { DEBUG, EASY=10, NORMAL=20, HARD=30 };

enum GameState {RUNNING, FINISHED_WIN, FINISHED_LOSS};


class MinesweeperBoard
{
    Field board[100][100];
    int width;
    int height;
    GameMode mode;
    GameState state;
    int MineQuantity;
    bool FIRSTMOVE = true;
    void display_Field(Field) const;
    bool isOutRange(int x, int y) const;
    bool WinCondition() const;
public:
    MinesweeperBoard(int width, int height, GameMode mode);
    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;
    int countMines(int x, int y) const;
    bool hasFlag(int x, int y) const;
    void toggleFlag(int x, int y);
    void revealField(int x, int y);
    bool isRevealed(int x, int y) const;
    GameState getGameState() const;
    char getFieldInfo(int x, int y) const;
    void debug_display() const;
};



#endif //TRY4_MINESWEEPERBOARD_H
