#include "Move.h"

enum COLOR 
{ 
	WHITE = 32, 
	BLACK = 177 
};

Move::Move()
{
}

Move::Move(int pX, int pY, int nX, int nY, char pla) :
	prevX(pX), prevY(pY), nextX(nX), nextY(nY), player(pla)
{
}

bool Move::InputChange()
{
	// Sprawdzenie, czy na odpowiednim polu znajduje siê pion nale¿¹cy do gracza
	if (getBoard(prevX, prevY) == player)
	{
		// Nie mo¿na siê ruszyæ na swojego pionka
		if (getBoard(nextX, nextY) == player)
		{
			return false;
		}
		// Sprawdzanie, czy pionek ruszy siê na dozwolone pole
		//TODO: Uwzglêdniæ to ¿e pionek mo¿e siê cofaæ tylko gdy mo¿e popchn¹æ pionka. 
		if ((nextX == (prevX + 1) || nextX == (prevX - 1)) &&
			(nextY == (prevY + 1) || nextY == (prevY - 1)))
		{
			pushFigure();
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	return true;
}

void Move::pushFigure()
{
	char opponent;
	if (player == 'x')
	{
		opponent = 'o';
	}
	else
	{
		opponent = 'x';
	}
	// Ruch pionka
	// Zastepuje stare miejsce pustymi
	if ((prevX + prevY) % 2 == 1)
	{
		setBoard(prevX, prevY, (char)COLOR(WHITE)); //biale pole
	}
	else
	{
		setBoard(prevX, prevY, (char)COLOR(BLACK)); //czarne pole
	}

	setBoard(nextX, nextY, char(player));
	// Wykrywanie przeciwników
	bool enemies[4];	// enemies[0] - góra, enemies[1] - prawa, enemies[2] - dó³, enemies[3] - lewa
						// Wartoœæ true oznacza ¿e znajduje siê tam pionek przeciwnika
						// Góra
	if (getBoard(nextX + 1, nextY) == opponent)
	{
		enemies[0] = true;
	}
	else
	{
		enemies[0] = false;
	}
	// Prawa
	if (getBoard(nextX, nextY + 1) == opponent)
	{
		enemies[1] = true;
	}
	else
	{
		enemies[1] = false;
	}
	// Dó³
	if (getBoard(nextX - 1, nextY) == opponent)
	{
		enemies[2] = true;
	}
	else
	{
		enemies[2] = false;
	}
	// Lewa
	if (getBoard(nextX, nextY - 1) == opponent)
	{
		enemies[3] = true;
	}
	else
	{
		enemies[3] = false;
	}

	for (int i = 0; i < 4; i++)
	{
		if (enemies[i] == true)
		{
			bool whatToDo = rearward(i, opponent);

			if (!whatToDo)
			{
				kick(i);
			}
		}
	}
}

void Move::kick(int x)
{
	// Góra
	if (x == 0)
	{
		if ((nextX + nextY) % 2 != 1)
		{
			setBoard(nextX + 1, nextY, (char)COLOR(WHITE)); //biale pole
		}
		else
		{
			setBoard(nextX + 1, nextY, (char)COLOR(BLACK)); //czarne pole
		}
	}
	// Prawa
	if (x == 1)
	{
		if ((nextX + nextY) % 2 != 1)
		{
			setBoard(nextX, nextY + 1, (char)COLOR(WHITE)); //biale pole
		}
		else
		{
			setBoard(nextX, nextY + 1, (char)COLOR(BLACK)); //czarne pole
		}
	}
	// Dó³
	if (x == 2)
	{
		if ((nextX + nextY) % 2 != 1)
		{
			setBoard(nextX - 1, nextY, (char)COLOR(WHITE)); //biale pole
		}
		else
		{
			setBoard(nextX - 1, nextY, (char)COLOR(BLACK)); //czarne pole
		}
	}
	// Lewa
	if (x == 3)
	{
		if ((nextX + nextY) % 2 != 1)
		{
			setBoard(nextX, nextY - 1, (char)COLOR(WHITE)); //biale pole
		}
		else
		{
			setBoard(nextX, nextY - 1, (char)COLOR(BLACK)); //czarne pole
		}
	}
}

bool Move::rearward(int x, char opponent)
{
	// Dol
	if (x == 0)
	{
		if (getBoard(nextX + 3, nextY) != opponent && (nextX + 3 < ROW))
		{
			if ((nextX + nextY) % 2 != 1)
			{
				setBoard(nextX + 1, nextY, (char)COLOR(WHITE)); //biale pole
				setBoard(nextX + 3, nextY, opponent); //bialy pion
				return true;
			}
			else
			{
				setBoard(nextX + 1, nextY, (char)COLOR(BLACK)); //czarne pole
				setBoard(nextX + 3, nextY, opponent); //czarny pion
				return true;
			}
		}
		return false;
	}
	// Prawa
	if (x == 1)
	{
		if (getBoard(nextX, nextY + 3) != opponent && (nextY + 3 < COL))
		{
			if ((nextX + nextY) % 2 != 1)
			{
				setBoard(nextX, nextY + 1, (char)COLOR(WHITE)); //biale pole
				setBoard(nextX, nextY + 3, opponent); //bialy pion
				return true;
			}
			else
			{
				setBoard(nextX, nextY + 1, (char)COLOR(BLACK)); //czarne pole
				setBoard(nextX, nextY + 3, opponent); //czarny pion
				return true;
			}
		}
		return false;
	}
	// Gora
	if (x == 2)
	{
		if (getBoard(nextX - 3, nextY) != opponent && (nextX - 3 > 0))
		{
			if ((nextX + nextY) % 2 != 1)
			{
				setBoard(nextX - 1, nextY, (char)COLOR(WHITE)); //biale pole
				setBoard(nextX - 3, nextY, opponent); //bialy pion
				return true;
			}
			else
			{
				setBoard(nextX - 1, nextY, (char)COLOR(BLACK)); //czarne pole
				setBoard(nextX - 3, nextY, opponent); //czarny pion
				return true;
			}
		}
		return false;
	}
	// Lewa
	if (x == 3)
		if (getBoard(nextX, nextY - 3) != opponent && (nextY - 3 > 0))
		{
			if ((nextX + nextY) % 2 != 1)
			{
				setBoard(nextX, nextY - 1, (char)COLOR(WHITE)); //biale pole
				setBoard(nextX, nextY - 3, opponent); //bialy pion
				return true;
			}
			else
			{
				setBoard(nextX, nextY - 1, (char)COLOR(BLACK)); //czarne pole
				setBoard(nextX, nextY - 3, opponent); //czarny pion
				return true;
			}
		}
	return false;
}

void Move::changePlayer()
{
	if (player == 'x')
	{
		player = 'o';
	}
	else
	{
		player = 'x';
	}
}

void Move::chooseSide()
{
	std::cout << "Wybierz kolor:\n";
	std::cout << "1 - czarny\n";
	std::cout << "2 - bialy\n";

	std::string str;
	std::cin >> str;

	if (str[0] == '1' && str.length() < 2)
	{
		player = 'x'; // czarny
	}
	else if (str[0] == '2' && str.length() < 2)
	{
		player = 'o'; // bialy
	}
	else
	{
		system("cls");
		std::cout << "\nBledne dane!\n";
		chooseSide();
	}
}

Move::~Move()
{
}

Move Move::setValu(int px1, int py1, int nx2, int ny2, char play)
{
	prevX = px1;
	prevY = py1;
	nextX = nx2;
	nextY = ny2;
	player = play;
	return *this;
}