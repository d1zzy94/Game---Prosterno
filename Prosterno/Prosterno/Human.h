#ifndef HUMAN_H
#define HUMAN_H
#include "Player.h"
#include <iostream>
#include <string>

class Human : public Player
{
public:
	Human();
	~Human();
	int MakeMove(char, Move&);
	void setName(char n) { name = n; }
	char getName() { return name; }
private:

};
#endif