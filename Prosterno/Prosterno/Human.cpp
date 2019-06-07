#include "Human.h"

Human::Human()
{
}

Human::~Human()
{
}

//zwraca -1 jesli blad
//zwraca 1 jesli jest ok,
//zwraca 2 jesli zapis 
//zwraca 3 jesli wczytanie
//zwraca 4 jesli wyjscie

int Human::MakeMove(char player, Move& m)
{
	std::string prev, next;
	std::cout << player << " wykonuje ruch: ";
	std::cin >> prev;

	if (prev == "save")
	{
		return 2;
	}
	if (prev == "menu")
	{
		return 5;
	}
	if (prev == "load")
	{
		return 3;
	}
	else if (prev == "exit")
	{
		return 4;
	}
	std::cin >> next;

	int x1, y1, x2, y2;

	//kontrola danych
	if (isdigit(prev[0]) == 0 ||
		isdigit(next[0]) == 0)
	{
		return -1;
	}
	else if (isalpha(prev[1]) == 0 ||
		isalpha(next[1]) == 0)
	{
		return -1;
	}

	if (prev[0] >= '0' && prev[0] <= '7') {}
	else
	{
		return -1;
	}

	if (next[0] >= '0' && next[0] <= '7') {}
	else
	{
		return -1;
	}

	if (prev[1] < 'a' && prev[1] > 'i')
	{
		return -1;
	}
	else if (next[1] < 'a' && next[1] > 'i')
	{
		return -1;
	}

	x1 = prev[0] - 48;
	y1 = prev[1] - 97;
	x2 = next[0] - 48;
	y2 = next[1] - 97;

	//jesli gracza nie ma w polu to podaj dane jeszcze raz
	if (m.getBoard(x1, y1) != m.getPlayer())
	{
		std::cout << "\nBrak pionka na polu, podaj dane jeszcze raz.\n";
		return -1;
	}

	//ustawienie 
	m.setValu(x1, y1, x2, y2, player);

	return 1;
}