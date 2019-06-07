#ifndef GAME_H
#define GAME_H

#include "Move.h"
#include "Player.h"
#include "Human.h"
#include "AI.h"
#include <iostream>
#include <cctype>
#include <fstream>
#include <cstdlib>

class Game
{
public:
	Game();
	~Game();
	void Startup();
	void Play();
	void whoseTurn();
	void playerChoose();
	void mainMenu();
	bool win();
	int exit() { return 0; }
	void save(Move&);
	void load(Move&);
	void setComp(bool x) { computer = x; }
private:
	Board board;
	Player *player;
	Player *human;
	Player *ai;
	Move m;
	bool computer = false;
};
#endif