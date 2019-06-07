#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#define ROW 8 //wiersze
#define COL 9 //kolumny

class Board
{
public:
	Board();
	~Board();
	void reset();
	void print();
	char getBoard(int x, int y) { return board[x][y]; }
	void setBoard(int x, int y, char var) { board[x][y] = var; }
	void clear_board();
protected:
	char board[ROW][COL];
};
#endif