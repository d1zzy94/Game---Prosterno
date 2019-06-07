#include "Game.h"


Game::Game()
{
	board.reset();
	player = NULL;
	human = NULL;
	ai = NULL;
	computer = false;
}

Game::~Game()
{
	delete player;
}

void Game::Startup()
{
	std::cout << "Twoje pionki sa oznaczone jako: o\n";
	std::cout << "Pionki przeciwnika natomiast jako: x\n\n";
	std::cout << "Ruszanie pionka: RzadKolumna Rzad2Kolumna2\n";
	std::cout << "RzadKolumna - miejsce z ktorego ruszamy pionkiem\n";
	std::cout << "RzadKolumna2 - miejce do ktorego chcemy ruszyc pionka\n";
	std::cout << "np: 6b 5a\n\n";
}

void Game::playerChoose()
{
	system("cls");
	m.chooseSide();
	system("cls");
}

void Game::mainMenu()
{
	int temp;
	std::cout << "1. Nowa Gra\n";
	std::cout << "2. Wczytaj\n";
	std::cout << "3. Zapisz\n";
	std::cout << "4. Wyjscie\n";
	std::cin >> temp;

	switch (temp)
	{
	case 1:
		std::cout << "Nowa Gra" << std::endl;
		m.reset();
		//wybor 'x' lub 'o'
		playerChoose();
		system("cls");
		//wybor human lub ai
		std::cout << "1. Czlowiek vs Czlowiek\n";
		std::cout << "2. Czlowiek vs Komputer\n";
		std::cin >> temp;
		if (temp == 1)
		{
			human = new Human();
		}
		else if (temp == 2)
		{
			computer = true;
			ai = new AI();
			if (m.getPlayer() == 'o')
			{
				player = ai;
				player->setName('x');
				human = new Human();
				player = human;
				player->setName('o');
			}
			else { 
				player = ai;
				player->setName('o'); 
				human = new Human();
				player = human;
				player->setName('x');
			}
		}

		Startup();
		m.print();
		Play();
		break;
	case 2:
		//wczytanie
		load(m);
		Play();
		break;
	case 3:
		//zapis
		save(m);
		system("cls");
		mainMenu();
		break;
	case 4:
		//wyjscie i zapis
		save(m);
		break;
	}
}

bool Game::win()
{
	for (int i = 0; i < COL; i++)
	{
		if ((i) % 2 == 1)
		{
			if (m.getBoard(0, i) == 'o')
				return true;
		}
		else if ((i) % 2 == 0)
		{
			if (m.getBoard(7, i) == 'x')
				return true;
		}
	}
	int count1 = 0;
	int count2 = 0;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (m.getBoard(i, j) == 'x') {
				count1++;
			}
			else if (m.getBoard(i, j) == 'o')
			{
				count2++;
			}
		}
	}
	if (count1 == 0)
		return true;
	else if (count2 == 0)
	{
		return true;
	}
	return false;
}

void Game::Play()
{
	int action = 9;
	bool result = true;

	while (result)
	{
		system("cls");
		Startup();
		m.print();

		do
		{
			if (computer) player = ai;
			if (computer && (player->getName() == m.getPlayer()) )
			{
				action = player->MakeMove(m.getPlayer(), m);
			}
			else
			{
				player = human;
				action = player->MakeMove(m.getPlayer(), m);
				player = ai;
			}

			if (action == 1)
				result = m.InputChange();

			if (!result)
				action = -1;

			if (action == -1) {
				system("cls");
				Startup();
				m.print();
				std::cout << "\nZle podane dane, sprobuj jeszcze raz.\n";
			}
			else if (action == 2)
			{
				save(m);
				std::cout << "\nZapisano!\n";
				_sleep(1000);
				Play();
			}
			else if (action == 3)
			{
				load(m);
				std::cout << "\Wczytano!\n";
				_sleep(1000);
				Play();
			}
			else if (action == 4)
			{
				std::cout << "\Do widzenia!\n";
				_sleep(1000);
				save(m);
				break;
			}
			else if (action == 5)
			{
				system("cls");
				mainMenu();
			}
		} while (action == -1);

		if (action == 4 || action == 5)
		{
			break;
		}

		bool whoWon = win();
		if (whoWon)
		{
			system("cls");
			Startup();
			m.print();
			std::cout << "\n" << m.getPlayer() << " wygral\n";
			system("pause");
			m.reset();
		}

		m.changePlayer();
	}
}

void Game::save(Move& m)
{
	std::ofstream outfile("save.txt");

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			outfile << m.getBoard(i, j);
		}
		outfile << "\n";
	}
	outfile << m.getPlayer() << "\n";
	outfile << int(computer) << "\n";
	
	if (computer)
	{
		player = ai;
		outfile << player->getName() << "\n";
	}
	else
	{
		outfile << "-" << "\n";
	}

	outfile.close();
}

void Game::load(Move& m)
{
	std::fstream infile;
	std::string str;
	infile.open("save.txt", std::ios::in | std::ios::out);
	int x = 0;
	if (infile.good() == true)
	{
		while (!infile.eof())
		{
			if (x < 8)
			{
				getline(infile, str);
				for (int i = 0; i < str.size(); i++)
				{
					m.setBoard(x, i, str[i]);
				}
				x++;
			}
			else
			{
				getline(infile, str);
				m.setPlayer(str[0]);

				getline(infile, str);
				computer = str[0];

				getline(infile, str);
				if (computer == true)
				{
					ai = new AI();
					ai->setName(str[0]);
					human = new Human();
					if (str[0] == 'x')
					{
						human->setName('o');
					}
					else
					{
						human->setName('x');
					}
				}
				break;
			}
		}
	}
	else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;

	infile.close();
}