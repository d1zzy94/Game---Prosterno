#include "Board.h"
enum COLOR 
{
	WHITE = 32, 
	BLACK = 177 
};

Board::Board()
{

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if ((i == 0 || i == 1) && (i + j) % 2 == 0) {
				board[i][j] = 'x'; //czarny pionek
								   //board[i][j] = ' '; //robocze
			}
			else if ((i == 6 || i == 7) && (i + j) % 2 == 1) {
				board[i][j] = 'o'; //bialy pionek
			}
			else if ((i + j) % 2 == 1)
			{
				board[i][j] = (char)COLOR(WHITE); //biale pole
			}
			else
			{
				board[i][j] = (char)COLOR(BLACK); //czarne pole
			}
		}
	}
}

Board::~Board()
{
}

void Board::reset()
{

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if ((i == 0 || i == 1) && (i + j) % 2 == 0) {
				board[i][j] = 'x'; //czarny pionek
			}
			else if ((i == 6 || i == 7) && (i + j) % 2 == 1) {
				board[i][j] = 'o'; //bialy pionek
								   //board[i][j] = ' '; //robocze
			}
			else if ((i + j) % 2 == 1)
			{
				board[i][j] = (char)COLOR(WHITE); //biale pole
			}
			else
			{
				board[i][j] = (char)COLOR(BLACK); //czarne pole
			}
		}
	}
}

void Board::print()
{
	int row, column, side = 0;
	std::cout << "Y->| a  b  c  d  e  f  g  h  i |\n";
	std::cout << "---|---------------------------|\n";
	for (row = 0; row < ROW; row++)
	{
		std::cout << side << "  |";
		side++;
		for (column = 0; column < COL; column++)
			if ((row + column) % 2 == 0)
			{
				if (board[row][column] != 0 && board[row][column] != 1)
				{
					std::cout << (char)COLOR(BLACK) << board[row][column] << (char)COLOR(BLACK);
				}
				else
				{
					std::cout << (char)COLOR(BLACK) << (char)COLOR(BLACK) << (char)COLOR(BLACK);
				}
			}
			else 
			{
				std::cout << " " << board[row][column] << " ";
			}
			std::cout << "|\n";

	}
	std::cout << "---|---------------------------|\n";
	std::cout << " ^ | a  b  c  d  e  f  g  h  i |\n";
	std::cout << " X |                           |\n\n";
}

void Board::clear_board()
{

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if ((i + j) % 2 == 1)
			{
				board[i][j] = (char)COLOR(WHITE); //biale pole
			}
			else
			{
				board[i][j] = (char)COLOR(BLACK); //czarne pole
			}
		}
	}
}