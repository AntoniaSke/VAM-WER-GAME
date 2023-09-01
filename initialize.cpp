#include <iostream>
#include "entities.hpp"
#include <time.h>
#include <vector>
#include <unistd.h>

using namespace std;
void initialization(vector<vector<int>> &boardex, int x, Vampire **vampires, Werewolf **werewolfs) // function to initialize the vampires and werewolfs
{

    int v_count = -1, w_count = -1;
    for (long unsigned int i = 0; i < boardex.size(); i++)
    {
        for (long unsigned int j = 0; j < boardex[i].size(); j++)
        {
            if (boardex[i][j] == 1)
            {
                vampires[++v_count] = new Vampire;
                vampires[v_count]->Creatures::set_pos(i, j);
                sleep(0.5);
            }
            else if (boardex[i][j] == 2)
            {

                werewolfs[++w_count] = new Werewolf;
                werewolfs[w_count]->Creatures::set_pos(i, j);
                sleep(0.5);
            }
        }
    }
}