#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include "entities.hpp"
using namespace std;
void gridex(vector<vector<string>> &board, vector<vector<int>> &boardex, int x, int y, Avatar *av) // function to convert the board to a vector of integers
{ 
    for (int i = 0; i < x; i++)
    {
        vector<int> row;
        for (int j = 0; j < y; j++)
        {
            if (board[i][j] == "|\033[1;34m^\033[0m|" || board[i][j] == "\033[1;34m^\033[0m|")
            {
                row.push_back(5);
            }
            else if (board[i][j] == "|\033[1;33m*\033[0m|" || board[i][j] == "\033[1;33m*\033[0m|")
            {
                row.push_back(6);
            }
            else if (board[i][j] == "|v|" || board[i][j] == "v|")
            {
                row.push_back(1);
            }
            else if (board[i][j] == "w|")
            {
                row.push_back(2);
            }
            else if (board[i][j] == "|\033[;32m&\033[0m|" || board[i][j] == "\033[;32m&\033[0m|")
            {
                row.push_back(7);
            }
            else if (board[i][j] == "\033[1;31mW\033[0m|" || board[i][j] == "|\033[1;31mW\033[0m|")
            {
                av->set_side('W');
                av->set_pos(i, j);
                row.push_back(4);
            }
            else if (board[i][j] == "|\033[1;31mV\033[0m|" || board[i][j] == "\033[1;31mV\033[0m|")
            {
                av->set_side('V');
                av->set_pos(i, j);
                row.push_back(3);
            }
            else
            {
                row.push_back(0);
            }
        }
        boardex.push_back(row);
    }
}

void boardex_to_board(vector<vector<int>> &boardex, vector<vector<string>> &board) // function to convert the vector of integers to a vector of strings
{ 
    for (long unsigned int i = 0; i < boardex.size(); i++)
    {
        for (long unsigned int j = 0; j < boardex[i].size(); j++)
        {
            if (boardex[i][j] == 0)
            {
                if (j == 0)
                {
                    board[i][j] = "|_|";
                }
                else
                {
                    board[i][j] = "_|";
                }
            }
            else if (boardex[i][j] == 1)
            {
                if (j == 0)
                {
                    board[i][j] = "|v|";
                }
                else
                {
                    board[i][j] = "v|";
                }
            }
            else if (boardex[i][j] == 2)
            {
                if (j == 0)
                {
                    board[i][j] = "|w|";
                }
                else
                {
                    board[i][j] = "w|";
                }
            }
            else if (boardex[i][j] == 3)
            {
                if (j == 0)
                {
                    board[i][j] = "|\033[1;31mV\033[0m|";
                }
                else
                {
                    board[i][j] = "\033[1;31mV\033[0m|";
                }
            }
            else if (boardex[i][j] == 4)
            {
                if (j == 0)
                {
                    board[i][j] = "|\033[1;31mW\033[0m|";
                }
                else
                {
                    board[i][j] = "\033[1;31mW\033[0m|";
                }
            }
            else if (boardex[i][j] == 5)
            {
                if (j == 0)
                {
                    board[i][j] = "|\033[1;34m^\033[0m|";
                }
                else
                {
                    board[i][j] = "\033[1;34m^\033[0m|";
                }
            }
            else if (boardex[i][j] == 6)
            {
                if (j == 0)
                {
                    board[i][j] = "|\033[1;33m*\033[0m|";
                }
                else
                {
                    board[i][j] = "\033[1;33m*\033[0m|";
                }
            }
            else
            {
                if (j == 0)
                {
                    board[i][j] = "|\033[;32m&\033[0m|";
                }
                else
                {
                    board[i][j] = "\033[;32m&\033[0m|";
                }
            }
        }
    }
}

int available(vector<vector<int>> &boardex, int x, int y)     // function to check if the next position is available
{                                                            
    int a;
    if (boardex[x][y] == 0 || boardex[x][y] == 7)
    {
        a = 1;
    }
    else
    {
        a = 0;
    }
    return a;
}