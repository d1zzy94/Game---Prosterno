#ifndef AI_H
#define AI_H
#define ROW 8
#define COL 9
#include "Player.h"
#include "Move.h"

#include <iostream>
#include <ctime>

struct Point
{
	int x;
	int y;
};

class AI : public Player
{
public:
	AI();
	~AI();
	int MakeMove(char player, Move& m);
	void setName(char n) { name = n; }
	char getName() { return name; }
private:
	Point tab[4];
};
#endif