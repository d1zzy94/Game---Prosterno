#ifndef PLAYER_H
#define PLAYER_H

#include"Move.h"

class Player
{
protected:
	char name;
public:
	Player();
	virtual ~Player();
	virtual int MakeMove(char, Move&) = 0;
	virtual void setName(char) = 0;
	virtual char getName() = 0;
};
#endif