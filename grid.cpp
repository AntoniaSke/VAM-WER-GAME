#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include "entities.hpp"
#include "board.hpp"

int random(int min, int max) // function to generate random numbers wthin a range
{
	static bool first = true;
	if (first)
	{

		first = false;
	}
	return min + rand() % ((max + 1) - min);
}

void grid(vector<vector<string>> &board, int x, int y, char c) // function to create the board
{
	string potion1, potion2, sides1, sides2;
	int xrand = rand() % x, yrand = rand() % y, p_randx = rand() % x, p_randy = rand() % y, t_randy, w_randy; // random numbers for the potions, the avatar and the enemies
	int vamp = 0, wolf = 0, lim = (x * y) / 15, lim2 = lim / y;
	potion1 = "|\033[;32m&\033[0m|";
	potion2 = "\033[;32m&\033[0m|";
	if (c == 'V')
	{
		sides1 = "|\033[1;31mV\033[0m|";
		sides2 = "\033[1;31mV\033[0m|";
	}
	else
	{
		sides1 = "|\033[1;31mW\033[0m|";
		sides2 = "\033[1;31mW\033[0m|";
	}
	for (int i = 0; i < x; i++)
	{

		vector<string> row;
		for (int j = 0; j < y; j++)
		{
			if (x < 30 && y < 30)
			{
				t_randy = (rand() % (y-lim2-2))+lim2+1, w_randy = (rand() % (y-lim2-2))+lim2+1;
			}
			else
			{
				t_randy = random(lim2+1, y-lim2-2), w_randy = random(lim2+1, y - lim2-2);
			}

			if ((j == t_randy && t_randy != yrand) && t_randy != p_randy)
			{

				if (j == 0)
				{
					row.push_back("|\033[1;34m^\033[0m|");
					continue;
				}
				if (j == y - 1)
				{
					row.push_back("\033[1;34m^\033[0m|");

					continue;
				}
				row.push_back("\033[1;34m^\033[0m|");
				continue;
			}

			if ((j == w_randy && w_randy != yrand) && w_randy != p_randy)
			{

				if (j == 0)
				{
					row.push_back("|\033[1;33m*\033[0m|");
					continue;
				}
				if (j == y - 1)
				{
					row.push_back("\033[1;33m*\033[0m|");

					continue;
				}
				row.push_back("\033[1;33m*\033[0m|");

				continue;
			}

			if (i == p_randx && j == p_randy)

			{

				if (j == 0)
				{
					row.push_back(potion1);

					continue;
				}
				if (j == y - 1)
				{
					row.push_back(potion2);

					continue;
				}
				row.push_back(potion2);

				continue;
			}
			if (i == xrand && j == yrand)

			{

				if (j == 0)
				{
					row.push_back(sides1);

					continue;
				}
				if (j == y - 1)
				{
					row.push_back(sides2);

					continue;
				}
				row.push_back(sides2);

				continue;
			}

			if (j <= lim2 && j == 0)
			{
				if (vamp != lim)
				{

					row.push_back("|v|");
					vamp++;
					continue;
				}

				row.push_back("|_|");
			}
			else
			{
				if (j <= lim2)
				{
					if (vamp != lim)
					{
						row.push_back("v|");
						vamp++;
						continue;
					}
				}
				if (j >= (y - lim2 - 1))
				{
					if (wolf != lim)
					{
						row.push_back("w|");
						wolf++;
						continue;
					}
				}

				row.push_back("_|");
			}
		}
		board.push_back(row);
	}

	print_b(board); // print the board
}
