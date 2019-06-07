#include "AI.h"

int AI::MakeMove(char player, Move& m)
{
	if (player == 'x')
	{
		int n = 0;
		for (int i = ROW; i >= 0; i--)
		{
			for (int j = COL; j >= 0; j--)
			{
				if (n == 3) break;
				if (m.getBoard(i, j) == 'x')
				{
					tab[n].x = i;
					tab[n].y = j;
					n++;
				}
			}
			if (n == 3) break;
		}
	}
	else if (player == 'o')
	{
		int n = 0;
		for (int i = 0; i < ROW; i++)
		{
			for (int j = 0; j < COL; j++)
			{
				if (n == 3) break;
				if (m.getBoard(i, j) == 'o')
				{
					tab[n].x = i;
					tab[n].y = j;
					n++;
				}
			}
			if (n == 3) break;
		}
	}

	srand(time(NULL));
	int random = (std::rand() % 3) + 0;

	tab[random];

	int x1 = tab[random].x;
	int y1 = tab[random].y;
	int x2 = 0;
	int y2 = 0;

	if (player == 'x')
	{
		//lewy dol
		if (tab[random].x + 1 >= 0 && tab[random].y - 1 >= 0
			&& tab[random].x + 1 < 9 && tab[random].y - 1 <= 9)
		{
			x2 = tab[random].x + 1;
			y2 = tab[random].y + 1;

		}
		//prawy dol
		else if (tab[random].x + 1 >= 0 && tab[random].y + 1 >= 0
			&& tab[random].x + 1 < 9 && tab[random].y + 1 <= 9)
		{
			x2 = tab[random].x + 1;
			y2 = tab[random].y + 1;

		}
	}
	else if (player == 'o')
	{
		//lewa gora
		if (tab[random].x - 1 >= 0 && tab[random].y - 1 >= 0
			&& tab[random].x - 1 < 9 && tab[random].y - 1 <= 9)
		{
			x2 = tab[random].x - 1;
			y2 = tab[random].y - 1;

		}
		//prawa gora
		else if (tab[random].x - 1 >= 0 && tab[random].y + 1 >= 0
			&& tab[random].x - 1 < 9 && tab[random].y + 1 <= 9)
		{
			x2 = tab[random].x - 1;
			y2 = tab[random].y + 1;

		}
	}
	else
	{
		MakeMove(player, m);
	}

	//ustawienie 
	m.setValu(x1, y1, x2, y2, player);

	return 1;
}

AI::AI()
{
}

AI::~AI()
{
}
