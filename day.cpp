#include <iostream>
#include "entities.hpp"
using namespace std;
bool is_day(int &count) // function to determine if is day or night
{
    if (count <= 5)
    {
        if (count == 1)
        {
            cout << "\033[34mIt is now day\033[0m" << endl;
        }
        return true;
    }
    else
    {
        if (count == 6)
        {
            cout << "\033[33mIt is now night\033[0m" << endl;
        }

        if (count % 5 == 0)
        {
            count = 0;
        }
        return false;
    }
}

void avatar_healing(bool day, Avatar *av, Vampire **vampires, Werewolf **werewolves, int size) // function to heal the team entities
{
    if (av->get_healing() > 0)
    {
        if (av->get_side() == 'W')
        {
            if (day == false)
            {
                for (int i = 0; i < size; i++)
                {
                    if (werewolves[i] != NULL)
                    {
                        werewolves[i]->set_health(3);
                    }
                }
                av->set_healing(av->get_healing() - 1);
                cout << "\033[32mYou just heal your team\033[0m" << endl;
            }
            else
            {
                cout << "\033[31mYou cant heal your team during the day\033[0m" << endl;
            }
        }
        else if (av->get_side() == 'V')
        {
            if (day == true)
            {
                for (int i = 0; i < size; i++)
                {
                    if (vampires[i] != NULL)
                    {
                        vampires[i]->set_health(3);
                    }
                }
                av->set_healing(av->get_healing() - 1);
                cout << "\033[32mYou just heal your team\033[0m" << endl;
            }
            else
            {
                cout << "\033[31mYou cant heal your team during the night\033[0m" << endl;
            }
        }
    }
    else
    {
        cout << "\033[31mYou dont have any healing potions\033[0m" << endl;
    }
}