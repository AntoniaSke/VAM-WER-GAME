#include <iostream>
#include <vector>
#include "entities.hpp"
#include <time.h>
#include "gridex.hpp"
#include <cstdlib>
#include <unistd.h>
using namespace std;
void move(vector<vector<string>> &board, vector<vector<int>> &boardex, char c, Avatar *av) // function to move the avatar
{
    long unsigned int x = av->get_x();
    long unsigned int y = av->get_y();
    if (av->get_side() == 'V')
    {
        if (c == 'w')
        {
            if (x != 0)
            {
                if (available(boardex, x - 1, y) == 1)
                {
                    av->set_pos(--x, y);
                    if (boardex[x][y] == 7)
                    {
                        av->set_healing(av->get_healing() + 1);
                    }
                    boardex[x][y] = 3;
                    boardex[x + 1][y] = 0;
                }
            }
        }
        if (c == 'a')
        {
            if (y != 0)
            {
                if ((available(boardex, x, y - 1)) == 1)
                {
                    av->set_pos(x, --y);
                    if (boardex[x][y] == 7)
                    {
                        av->set_healing(av->get_healing() + 1);
                    }
                    boardex[x][y] = 3;
                    boardex[x][y + 1] = 0;
                }
            }
        }
        if (c == 'd')
        {
            if (y != boardex[0].size() - 1)
            {
                if (available(boardex, x, y + 1) == 1)
                {
                    av->set_pos(x, ++y);
                    if (boardex[x][y] == 7)
                    {
                        av->set_healing(av->get_healing() + 1);
                    }
                    boardex[x][y] = 3;
                    boardex[x][y - 1] = 0;
                }
            }
        }
        if (c == 's')
        {
            if (x != boardex.size() - 1)
            {
                if (available(boardex, x + 1, y) == 1)
                {
                    av->set_pos(++x, y);
                    if (boardex[x][y] == 7)
                    {
                        av->set_healing(av->get_healing() + 1);
                    }
                    boardex[x][y] = 3;
                    boardex[x - 1][y] = 0;
                }
            }
        }
        boardex_to_board(boardex, board);
    }
    else if (av->get_side() == 'W')
    {
        if (c == 'w')
        {
            if (x != 0)
            {
                if (available(boardex, x - 1, y) == 1)
                {

                    av->set_pos(--x, y);
                    if (boardex[x][y] == 7)
                    {
                        av->set_healing(av->get_healing() + 1);
                    }
                    boardex[x][y] = 4;
                    boardex[x + 1][y] = 0;
                }
            }
        }
        if (c == 'a')
        {
            if (y != 0)
            {
                if (y != 0)
                {
                    if ((available(boardex, x, y - 1)) == 1)
                    {
                        av->set_pos(x, --y);
                        if (boardex[x][y] == 7)
                        {
                            av->set_healing(av->get_healing() + 1);
                        }
                        boardex[x][y] = 4;
                        boardex[x][y + 1] = 0;
                    }
                }
            }
        }
        if (c == 'd')
        {
            if (y != boardex[0].size() - 1)
            {
                if ((available(boardex, x, y + 1)) == 1)
                {
                    av->set_pos(x, ++y);
                    if (boardex[x][y] == 7)
                    {
                        av->set_healing(av->get_healing() + 1);
                    }
                    boardex[x][y] = 4;
                    boardex[x][y - 1] = 0;
                }
            }
        }
        if (c == 's')
        {
            if (x != boardex.size() - 1)
            {
                if (available(boardex, x + 1, y) == 1)
                {
                    av->set_pos(++x, y);
                    if (boardex[x][y] == 7)
                    {
                        av->set_healing(av->get_healing() + 1);
                    }
                    boardex[x][y] = 4;
                    boardex[x - 1][y] = 0;
                }
            }
            boardex_to_board(boardex, board);
        }
    }
}
void try_to_move(vector<vector<int>> &boardex, vector<vector<string>> &board, Vampire **vampires, int rows, int columns, int i)
{ // function to moveaway the vampires
    int x1 = vampires[i]->get_x();
    int y1 = vampires[i]->get_y();
    int x;
    int y;
    vampires[i]->move(rows, columns);
    x = vampires[i]->get_x();
    y = vampires[i]->get_y();
    if (boardex[x][y] != 0)
    {
        vampires[i]->set_pos(x1, y1);
    }
    else
    {
        boardex[x1][y1] = 0;
        boardex[x][y] = 1;
        boardex_to_board(boardex, board);
    }
}
void move_vampire(vector<vector<int>> &boardex, vector<vector<string>> &board, Vampire **vampires, int rows, int columns, int size) // function to move the vampires
{

    for (int i = 0; i < size; i++)
    {
        if (vampires[i] != NULL)
        {
            try_to_move(boardex, board, vampires, rows, columns, i);
        }
    }
}
void try_to_move(vector<vector<int>> &boardex, vector<vector<string>> &board, Werewolf **werewolves, int rows, int columns, int i)
{ // function to moveaway the werewolves
    int x1 = werewolves[i]->get_x();
    int y1 = werewolves[i]->get_y();
    int x;
    int y;
    werewolves[i]->move(rows, columns);
    x = werewolves[i]->get_x();
    y = werewolves[i]->get_y();
    if (boardex[x][y] != 0)
    {
        werewolves[i]->set_pos(x1, y1);
    }
    else
    {
        boardex[x1][y1] = 0;
        boardex[x][y] = 2;
        boardex_to_board(boardex, board);
    }
}
void move_werewolf(vector<vector<int>> &boardex, vector<vector<string>> &board, Werewolf **werewolves, int rows, int columns, int size) // function to move the werewolves
{

    for (int i = 0; i < size; i++)
    {
        if (werewolves[i] != NULL)
        {
            try_to_move(boardex, board, werewolves, rows, columns, i);
        }
    }
}

void disappear(vector<vector<int>> &boardex, vector<vector<string>> &board, Vampire **vampires, int i) // function to make the vampires disappear
{
    int x = vampires[i]->get_x();
    int y = vampires[i]->get_y();
    boardex[x][y] = 0;
    delete vampires[i];
    vampires[i] = NULL;
    boardex_to_board(boardex, board);
}
void disappear(vector<vector<int>> &boardex, vector<vector<string>> &board, Werewolf **werewolves, int j) // function to make the werewolves disappear
{
    int x = werewolves[j]->get_x();
    int y = werewolves[j]->get_y();
    boardex[x][y] = 0;
    delete werewolves[j];
    werewolves[j] = NULL;
    boardex_to_board(boardex, board);
}

void v_heal(Vampire **vampires, int size) // function to heal the vampires
{

    for (int i = 0; i < size; i++)
    {

        if (vampires[i] != NULL)
        {
            int x1 = vampires[i]->get_x();
            int y1 = vampires[i]->get_y();

            for (int j = i + 1; j < size; j++)
            {

                if (vampires[j] != NULL)
                {
                    int x2 = vampires[j]->get_x();
                    int y2 = vampires[j]->get_y();

                    if (x1 == x2)
                    {
                        if (abs(y1 - y2) == 1)
                        {
                            if (vampires[i]->get_health() < 3)
                            {
                                int x = rand() % 2;
                                if (x == 1 && vampires[j]->get_medical() > 0)
                                {
                                    vampires[i]->set_health(vampires[i]->get_health() + 1);
                                    vampires[j]->set_medical(vampires[j]->get_medical() - 1);
                                }
                            }
                            else if (vampires[j]->get_health() < 3)
                            {
                                int x = rand() % 2;
                                if (x == 1 && vampires[i]->get_medical() > 0)
                                {
                                    vampires[j]->set_health(vampires[j]->get_health() + 1);
                                    vampires[i]->set_medical(vampires[i]->get_medical() - 1);
                                }
                            }
                        }
                    }
                    else if (y1 == y2)
                    {
                        if (abs(x1 - x2) == 1)
                        {
                            if (vampires[i]->get_health() < 3)
                            {
                                int x = rand() % 2;
                                if (x == 1 && vampires[j]->get_medical() > 0)
                                {
                                    vampires[i]->set_health(vampires[i]->get_health() + 1);
                                    vampires[j]->set_medical(vampires[j]->get_medical() - 1);
                                }
                            }
                            else if (vampires[j]->get_health() < 3)
                            {
                                int x = rand() % 2;
                                if (x == 1 && vampires[i]->get_medical() > 0)
                                {
                                    vampires[j]->set_health(vampires[j]->get_health() + 1);
                                    vampires[i]->set_medical(vampires[i]->get_medical() - 1);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void w_heal(Werewolf **werewolves, int size) // function to heal the werewolves
{

    for (int i = 0; i < size; i++)
    {

        if (werewolves[i] != NULL)
        {
            int x1 = werewolves[i]->get_x();
            int y1 = werewolves[i]->get_y();

            for (int j = i + 1; j < size; j++)
            {

                if (werewolves[j] != NULL)
                {
                    int x2 = werewolves[j]->get_x();
                    int y2 = werewolves[j]->get_y();
                    if (x1 == x2)
                    {
                        if (abs(y1 - y2) == 1)
                        {
                            if (werewolves[i]->get_health() < 3)
                            {
                                int x = rand() % 2;
                                if (x == 1 && werewolves[j]->get_medical() > 0)
                                {
                                    werewolves[i]->set_health(werewolves[i]->get_health() + 1);
                                    werewolves[j]->set_medical(werewolves[j]->get_medical() - 1);
                                }
                            }
                            else if (werewolves[j]->get_health() < 3)
                            {
                                int x = rand() % 2;
                                if (x == 1 && werewolves[i]->get_medical() > 0)
                                {
                                    werewolves[j]->set_health(werewolves[j]->get_health() + 1);
                                    werewolves[i]->set_medical(werewolves[i]->get_medical() - 1);
                                }
                            }
                        }
                    }
                    else if (y1 == y2)
                    {
                        if (abs(x1 - x2) == 1)
                        {
                            if (werewolves[i]->get_health() < 3)
                            {
                                int x = rand() % 2;
                                if (x == 1 && werewolves[j]->get_medical() > 0)
                                {
                                    werewolves[i]->set_health(werewolves[i]->get_health() + 1);
                                    werewolves[j]->set_medical(werewolves[j]->get_medical() - 1);
                                }
                            }
                            else if (werewolves[j]->get_health() < 3)
                            {
                                int x = rand() % 2;
                                if (x == 1 && werewolves[i]->get_medical() > 0)
                                {
                                    werewolves[j]->set_health(werewolves[j]->get_health() + 1);
                                    werewolves[i]->set_medical(werewolves[i]->get_medical() - 1);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void fight(vector<vector<int>> &boardex, vector<vector<string>> &board, Vampire **vampires, Werewolf **werewolves, int size, int rows, int columns) // function to fight between vampires and werewolves
{
    int x, random;

    for (int i = 0; i < size; i++)
    {

        if (vampires[i] != NULL)
        {
            int xv = vampires[i]->get_x();
            int yv = vampires[i]->get_y();
            for (int j = 0; j < size; j++)
            {

                if (werewolves[j] != NULL)
                {
                    int xw = werewolves[j]->get_x();
                    int yw = werewolves[j]->get_y();

                    if (xv == xw)
                    {
                        if (abs(yv - yw) == 1)
                        {
                            if (vampires[i]->get_power() > werewolves[j]->get_power())
                            {
                                if (werewolves[j]->get_defense() > vampires[i]->get_power())
                                {
                                    continue;
                                }
                                try_to_move(boardex, board, werewolves, rows, columns, j);
                                if (xw == werewolves[j]->get_x() && yw == werewolves[j]->get_y())
                                {
                                    x = vampires[i]->get_power() - werewolves[j]->get_defense();
                                    werewolves[j]->set_health(werewolves[j]->get_health() - x);
                                    if (werewolves[j]->get_health() <= 0)
                                    {
                                        disappear(boardex, board, werewolves, j);
                                        break;
                                    }
                                }
                            }
                            else if (vampires[i]->get_power() == werewolves[j]->get_power())
                            {
                                random = rand() % 2;
                                if (random == 0)
                                {
                                    if (werewolves[j]->get_defense() > vampires[i]->get_power())
                                    {
                                        continue;
                                    }
                                    try_to_move(boardex, board, werewolves, rows, columns, j);
                                    if (xw == werewolves[j]->get_x() && yw == werewolves[j]->get_y())
                                    {
                                        x = vampires[i]->get_power() - werewolves[j]->get_defense();
                                        werewolves[j]->set_health(werewolves[j]->get_health() - x);
                                        if (werewolves[j]->get_health() <= 0)
                                        {
                                            disappear(boardex, board, werewolves, j);
                                            break;
                                        }
                                    }
                                }
                                else
                                {
                                    if (vampires[i]->get_defense() > werewolves[j]->get_power())
                                    {
                                        continue;
                                    }
                                    try_to_move(boardex, board, vampires, rows, columns, i);
                                    if (xv == vampires[i]->get_x() && yv == vampires[i]->get_y())
                                    {
                                        x = werewolves[j]->get_power() - vampires[i]->get_defense();
                                        vampires[i]->set_health(vampires[i]->get_health() - x);
                                        if (vampires[i]->get_health() <= 0)
                                        {
                                            disappear(boardex, board, vampires, i);
                                            break;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                if (vampires[i]->get_defense() > werewolves[j]->get_power())
                                {
                                    continue;
                                }
                                try_to_move(boardex, board, vampires, rows, columns, i);
                                if (xv == vampires[i]->get_x() && yv == vampires[i]->get_y())
                                {
                                    x = werewolves[j]->get_power() - vampires[i]->get_defense();
                                    vampires[i]->set_health(vampires[i]->get_health() - x);
                                    if (vampires[i]->get_health() <= 0)
                                    {
                                        disappear(boardex, board, vampires, i);
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    else if (vampires[i]->get_y() == werewolves[j]->get_y())
                    {
                        if (abs(vampires[i]->get_x() - werewolves[j]->get_x()) == 1)
                        {
                            if (vampires[i]->get_power() > werewolves[j]->get_power())
                            {
                                if (werewolves[j]->get_defense() > vampires[i]->get_power())
                                {
                                    continue;
                                }
                                try_to_move(boardex, board, werewolves, rows, columns, j);
                                if (xw == werewolves[j]->get_x() && yw == werewolves[j]->get_y())
                                {
                                    x = vampires[i]->get_power() - werewolves[j]->get_defense();
                                    werewolves[j]->set_health(werewolves[j]->get_health() - x);
                                    if (werewolves[j]->get_health() <= 0)
                                    {
                                        disappear(boardex, board, werewolves, j);
                                        break;
                                    }
                                }
                            }
                            else if (vampires[i]->get_power() == werewolves[j]->get_power())
                            {
                                random = rand() % 2;
                                if (random == 0)
                                {
                                    if (werewolves[j]->get_defense() > vampires[i]->get_power())
                                    {
                                        continue;
                                    }
                                    try_to_move(boardex, board, werewolves, rows, columns, j);
                                    if (xw == werewolves[j]->get_x() && yw == werewolves[j]->get_y())
                                    {
                                        x = vampires[i]->get_power() - werewolves[j]->get_defense();
                                        werewolves[j]->set_health(werewolves[j]->get_health() - x);
                                        if (werewolves[j]->get_health() <= 0)
                                        {
                                            disappear(boardex, board, werewolves, j);
                                            break;
                                        }
                                    }
                                }
                                else
                                {
                                    if (vampires[i]->get_defense() > werewolves[j]->get_power())
                                    {
                                        continue;
                                    }
                                    try_to_move(boardex, board, vampires, rows, columns, i);
                                    if (xv == vampires[i]->get_x() && yv == vampires[i]->get_y())
                                    {
                                        x = werewolves[j]->get_power() - vampires[i]->get_defense();
                                        vampires[i]->set_health(vampires[i]->get_health() - x);
                                        if (vampires[i]->get_health() <= 0)
                                        {
                                            disappear(boardex, board, vampires, i);
                                            break;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                if (vampires[i]->get_defense() > werewolves[j]->get_power())
                                {
                                    continue;
                                }
                                try_to_move(boardex, board, vampires, rows, columns, i);
                                if (xv == vampires[i]->get_x() && yv == vampires[i]->get_y())
                                {
                                    x = werewolves[j]->get_power() - vampires[i]->get_defense();
                                    vampires[i]->set_health(vampires[i]->get_health() - x);
                                    if (vampires[i]->get_health() <= 0)
                                    {
                                        disappear(boardex, board, vampires, i);
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void game_action(vector<vector<int>> &boardex, vector<vector<string>> &board, Vampire **vampires, Werewolf **werewolves, int size, int rows, int columns) // function that calls all the functions and sets the game in action
{
    v_heal(vampires, size);
    w_heal(werewolves, size);

    fight(boardex, board, vampires, werewolves, size, rows, columns);
}