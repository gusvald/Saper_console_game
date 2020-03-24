#include <gtest/gtest.h>
#include "../src/MinesweeperBoard.h"

//https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md
//https://google.github.io/styleguide/cppguide.html
//https://github.com/google/googletest
//https://github.com/google/googletest/tree/master/googletest/samples

// predefined mine field layout:
// field at coordinates x,y has mine, if any of the following is true
// - x==y (all fields on main diagonal have mines)
// - y==0 (all fields in first row have mines)
// - x==0 and y%2 == 0 (every second field in first column has mine)
//
// Assuming we have 9x7 board size, debug_display() should show:

// [M..][M..][M..][M..][M..][M..][M..][M..][M..]
// [...][M..][...][...][...][...][...][...][...]
// [M..][...][M..][...][...][...][...][...][...]
// [...][...][...][M..][...][...][...][...][...]
// [M..][...][...][...][M..][...][...][...][...]
// [...][...][...][...][...][M..][...][...][...]
// [M..][...][...][...][...][...][M..][...][...]

namespace {

    const unsigned int WIDTH = 9;
    const unsigned int HEIGHT = 7;

// - DEBUG  - predefined mine layout
    TEST(MinesweeperBoardTest, getMineCountDebug) {
    MinesweeperBoard uut(WIDTH, HEIGHT, DEBUG);
    EXPECT_EQ(18,  uut.getMineCount());
}

// - EASY   - 10% of game fields with mines (random)
TEST(MinesweeperBoardTest, getMineCountEasy) {
MinesweeperBoard uut(WIDTH, HEIGHT, EASY);
EXPECT_EQ(6,  uut.getMineCount());
}

// - NORMAL - 20% of game fields with mines (random)
TEST(MinesweeperBoardTest, getMineCountNormal) {
MinesweeperBoard uut(WIDTH, HEIGHT, NORMAL);
EXPECT_EQ(12,  uut.getMineCount());
}

// - HARD   - 30% of game fields with mines (random)
TEST(MinesweeperBoardTest, getMineCountHard) {
MinesweeperBoard uut(WIDTH, HEIGHT, HARD);
EXPECT_EQ(18,  uut.getMineCount());
}

// simple getters
TEST(MinesweeperBoardTest, getBoardWidth) {
MinesweeperBoard uut(WIDTH, HEIGHT, DEBUG);
EXPECT_EQ(WIDTH,  uut.getBoardWidth());
}

// simple getters
TEST(MinesweeperBoardTest, getBoardHeight) {
MinesweeperBoard uut(WIDTH, HEIGHT, DEBUG);
EXPECT_EQ(HEIGHT,  uut.getBoardHeight());
}

// count mines around (x,y) position
// if the field at (x,y) was not revealed - return -1
TEST(MinesweeperBoardTest, countMinesArroundXYIftheFieldWasNotRevealed) {
MinesweeperBoard uut(WIDTH, HEIGHT, DEBUG);
EXPECT_FALSE(uut.isRevealed(1, 0));
EXPECT_EQ(-1, uut.countMines(1, 0));
}

// count mines around (x,y) position
// if the field at (x,y) was not revealed - return -1
TEST(MinesweeperBoardTest, countMinesIfEitherXOrYIsOutsideBoard) {
MinesweeperBoard uut(WIDTH, HEIGHT, DEBUG);
EXPECT_EQ(-1, uut.countMines(-1, 0));
EXPECT_EQ(-1, uut.countMines(0, -1));
EXPECT_EQ(-1, uut.countMines(-1, -1));

EXPECT_EQ(-1, uut.countMines(WIDTH + 1, 0));
EXPECT_EQ(-1, uut.countMines(0, HEIGHT + 1));
EXPECT_EQ(-1, uut.countMines(WIDTH + 1, HEIGHT + 1));
}

// count mines around (x,y) position
// Examples for DEBUG layout (assuming the field is already revealed)
// - countMines(0,1) should return 4
// - countMines(9,2) should return 0
// - countMines(1,2) should return 3
// - countMines(7,6) should return 1
TEST(MinesweeperBoardTest, countMinesIfFieldIsRelealed) {
MinesweeperBoard uut(WIDTH, HEIGHT, DEBUG);

uut.revealField(1, 0);
EXPECT_EQ(4, uut.countMines(1, 0));

uut.revealField(8, 2);
EXPECT_EQ(0, uut.countMines(8, 2));

uut.revealField(2, 1);
EXPECT_EQ(3, uut.countMines(2, 1));

uut.revealField(7, 6);
EXPECT_EQ(1, uut.countMines(7, 6));
}


// - RUNNING - if the game is not yet finished
TEST(MinesweeperBoardTest, IfGameIsNotFinished) {
MinesweeperBoard uut(WIDTH, HEIGHT, DEBUG);
EXPECT_EQ(RUNNING,  uut.getGameState());
}

// field was already flagged
TEST(MinesweeperBoardTest, ReturnFalseWasAlreadyFlagged) {
MinesweeperBoard uut(WIDTH, HEIGHT, DEBUG);
uut.revealField(0, 0);
uut.toggleFlag(0, 0);
EXPECT_FALSE(uut.hasFlag(0, 0));
}

// x or y is outside board
TEST(MinesweeperBoardTest, DoNothingIfXorYIsOutsideBoard) {
MinesweeperBoard uut(WIDTH, HEIGHT, DEBUG);
uut.toggleFlag(1, 1);
EXPECT_TRUE(uut.hasFlag(1, 1));

uut.revealField(1, 1);
EXPECT_FALSE(uut.isRevealed(1, 1));
}

// char getFieldInfo(int x, int y) const;
// if x or y is outside board - return '#' character
TEST(MinesweeperBoardTest, ifXorYisOutsideBoardReturnHashCharacter) {
MinesweeperBoard uut(WIDTH, HEIGHT, DEBUG);
EXPECT_EQ('#', uut.getFieldInfo(-1, -1));
EXPECT_EQ('#', uut.getFieldInfo(WIDTH + 1, HEIGHT + 1));
}

// char getFieldInfo(int x, int y) const;
// if the field is not revealed and has a flag - return 'F' character
TEST(MinesweeperBoardTest, ifTheFieldIsNotRevaledAndHasAFlagRetrunFCharacter) {
MinesweeperBoard uut(WIDTH, HEIGHT, DEBUG);
EXPECT_FALSE(uut.isRevealed(0, 0));
EXPECT_FALSE(uut.hasFlag(0, 0));
EXPECT_EQ('_', uut.getFieldInfo(0, 0));

uut.toggleFlag(0, 0);
EXPECT_EQ('F', uut.getFieldInfo(0, 0));
}

// char getFieldInfo(int x, int y) const;
// if the field is revealed and has mine - return 'x' character
TEST(MinesweeperBoardTest, ifTheFieldIsRevealedAndHasAMineRetrunXCharacter) {
MinesweeperBoard uut(WIDTH, HEIGHT, DEBUG);
EXPECT_FALSE(uut.isRevealed(0, 0));
uut.revealField(0,0);

EXPECT_EQ('x', uut.getFieldInfo(0, 0));
}

// char getFieldInfo(int x, int y) const;
// if the field is revealed and has 0 mines around - return ' ' (space) character
TEST(MinesweeperBoardTest, ifTheFieldIsRevealedAndHasZeroMinesAroundRetrunSpace) {
MinesweeperBoard uut(WIDTH, HEIGHT, DEBUG);
EXPECT_FALSE(uut.isRevealed(8, 3));
uut.revealField(8,3);

EXPECT_EQ(' ', uut.getFieldInfo(8, 3));
}

// char getFieldInfo(int x, int y) const;
// if the field is revealed and has some mines around - return '1' ... '8' (number of mines as a digit)
TEST(MinesweeperBoardTest, ifTheFieldIsRevaledAndHasSomeMinesAroudRetrunNumberOfMines) {
MinesweeperBoard uut(WIDTH, HEIGHT, DEBUG);
EXPECT_FALSE(uut.isRevealed(3, 1));
uut.revealField(3, 1);

EXPECT_EQ('3', uut.getFieldInfo(3, 1));
}

// return true if the field at (x,y) position was marked with flag
TEST(MinesweeperBoardTest, ReturnTrueIfTheFieldAtXYPositionWasMarkedWithFlag) {
MinesweeperBoard uut(WIDTH, HEIGHT, DEBUG);

for (unsigned int x = 0; x < uut.getBoardWidth(); x++) {
for (unsigned int y = 0; y < uut.getBoardHeight(); y++) {
EXPECT_FALSE(uut.hasFlag(x, y));
uut.toggleFlag(x, y);
EXPECT_TRUE(uut.hasFlag(x, y));
}
}
}

// return false if x or y is outside board
TEST(MinesweeperBoardTest, ReturnFalseIfXorYIsOutsideBoard) {
MinesweeperBoard uut(WIDTH, HEIGHT, DEBUG);
EXPECT_FALSE(uut.hasFlag(-1, -1));
EXPECT_FALSE(uut.hasFlag(WIDTH + 1, HEIGHT + 1));
}

// there is no flag on the field
TEST(MinesweeperBoardTest, ReturnFalseIfNoFlagOOnTheField) {
MinesweeperBoard uut(WIDTH, HEIGHT, DEBUG);
EXPECT_FALSE(uut.hasFlag(0, 0));
}

// field was already revealed
TEST(MinesweeperBoardTest, ReturnFalseWasAlreadyRevealed) {
MinesweeperBoard uut(WIDTH, HEIGHT, DEBUG);
uut.revealField(0, 0);
uut.toggleFlag(0, 0);
EXPECT_FALSE(uut.hasFlag(0, 0));
}


// try to reveal the field at (x,y)
// Do nothing if any of the following is true
// - either x or y is outside board
TEST(MinesweeperBoardTest, tryToRevealToTheFieldDoNothingIfXYIsOutsideBoard) {
MinesweeperBoard uut(WIDTH, HEIGHT, DEBUG);

uut.revealField(-1, 0);
uut.revealField(0, -1);
uut.revealField(-1, -1);

uut.revealField(WIDTH + 1, HEIGHT+ 1);
uut.revealField(WIDTH + 1, 0);
uut.revealField(0, HEIGHT+ 1);
}

// FINISHED_LOSS - if the player revealed field with mine
TEST(MinesweeperBoardTest, playerLoss) {
MinesweeperBoard uut(WIDTH, HEIGHT, DEBUG);

uut.revealField(0, 0);
EXPECT_TRUE(uut.isRevealed(0, 0));
EXPECT_EQ(FINISHED_LOSS, uut.getGameState());
}

TEST(MinesweeperBoardTest, GameStateRunningTooManyFlags) {
MinesweeperBoard uut(WIDTH, HEIGHT, DEBUG);

uut.toggleFlag(1, 0);

for (int x = 0; x < uut.getBoardHeight(); x++) {
for (int y = 0 ; y <uut.getBoardWidth(); y++) {
if ( x == y || x == 0 || ( y == 0 && x % 2 == 0)) {
uut.toggleFlag(x, y);
}
}
}

uut.toggleFlag(8, 0);
EXPECT_EQ(RUNNING, uut.getGameState());
}

// FINISHED_WIN - if the player won the game:
// all unrevealed fields have mines
TEST(MinesweeperBoardTest, playerWinAllUnrevealedFieldsHaveMines) {
MinesweeperBoard uut(WIDTH, HEIGHT, DEBUG);

for (int i = 0; i < uut.getBoardHeight(); i++) {
for (int j = 0 ; j < uut.getBoardWidth(); j++) {
if (!(i == j || i == 0 || (j == 0 && i % 2 == 0))) {
uut.revealField(j, i);
}
}
}

EXPECT_EQ(FINISHED_WIN, uut.getGameState());
}
}

