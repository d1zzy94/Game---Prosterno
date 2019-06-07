#ifndef MOVE_H
#define MOVE_H
#include "Board.h"
#include <iostream>
#include <string>

class Move : public Board
{
public:
	Move();
	Move(int, int, int, int, char);
	bool InputChange();
	void pushFigure();
	void chooseSide();

	char getPlayer() { return player; }
	void setPlayer(char p) { player = p; }

	int getPrevX() { return prevX; }
	int getPrevY() { return prevY; }
	int getNextX() { return nextX; }
	int getNextY() { return nextY; }

	void setPrevX(int n) { prevX = n; }
	void setPrevY(int n) { prevY = n; }
	void setNextX(int n) { nextX = n; }
	void setNextY(int n) { nextY = n; }

	Move setValu(int, int, int, int, char);
	void kick(int);
	bool rearward(int, char);
	void changePlayer();

	~Move();
protected:
	int prevX;
	int prevY;
	int nextX;
	int nextY;
	char player;
};
#endif