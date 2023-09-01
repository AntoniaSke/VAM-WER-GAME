#include <iostream>
#include <vector>
#include <unistd.h>
#include "grid.hpp"
#include "entities.hpp"
#include <time.h>
#include "initialize.hpp"
#include "gridex.hpp"
#include "moveobj.hpp"
#include "board.hpp"
#include "day.hpp"
using namespace std;

int main()
{
	srand(time(NULL)); // seed for random number generator
	int x, y, count = 0;
	char sides, c;
	bool day;
	Avatar *av = new Avatar;
	cout << "\033[1;35mWelcome to the Vampires vs Werewolves  game\033[0m" << endl;
	cout << "Enter number of rows"
		 << "\n";
	cin >> x; // user input for number of rows and columns
	cout << "Enter number of columns"
		 << "\n";
	cin >> y;				 // user input for number of rows and columns
	int size = (x * y) / 15; // number of vampires and werewolves
	Werewolf **werewolves = new Werewolf *[size];
	Vampire **vampires = new Vampire *[size];

	cout << "Choose sides 'V' or 'W'" << endl;
	cin >> sides; // user input for choosing sides
	av->set_side(sides);
	vector<vector<string>> board;
	grid(board, x, y, av->get_side());
	vector<vector<int>> boardex;
	gridex(board, boardex, x, y, av);
	initialization(boardex, size, vampires, werewolves);

	while (Vampire::v_population != 0 && Werewolf::w_population != 0) // while loop for the game
	{

		cout << endl;
		cin >> c;
		count++; // counter for day and night

		if (c == 'p') // game  pause
		{

			system("clear"); // clear screen

			cout << "\033[1;31mPaused\033[0m"
				 << "	"
				 << "Vampires: " << Vampire::v_population << "	"
				 << "Werewolves: " << Werewolf::w_population << "  Potions: " << av->get_healing() << endl;
			print_b(board);

			cin >> c;
			if (c == 'q') // quit the game
			{
				cout << "\033[1;31mGame Over\033[0m" << endl;
				break;
			}
		}

		move(board, boardex, c, av);
		move_vampire(boardex, board, vampires, x, y, size);
		move_werewolf(boardex, board, werewolves, x, y, size);
		game_action(boardex, board, vampires, werewolves, size, x, y);
		cout << endl;
		system("clear"); // clear screen

		print_b(board);		 // print the board
		day = is_day(count); // check if it is day or night

		if (c == 'h') // heal the team
		{

			cout << endl;
			avatar_healing(day, av, vampires, werewolves, size);
		}
	}
	if (c != 'q') // if the game is not quit
	{
		if (av->get_side() == 'V') // check who won
		{
			if (Vampire::v_population == 0)
			{
				cout << "\033[1;31mWerewolves have won !\033[0m" << endl;
			}
			else
			{
				cout << "\033[1;32mVampires have won !\033[0m" << endl;
			}
		}
		if (av->get_side() == 'W')
		{
			if (Werewolf::w_population == 0)
			{
				cout << "\033[1;31mVampires have won !\033[0m" << endl;
			}
			else
			{
				cout << "\033[1;32mWerewolves have won !\033[0m" << endl;
			}
		}
	}
	cout << endl;
	delete av; // delete the dynamic memory
	delete[] vampires;
	delete[] werewolves;
	return 0;
}