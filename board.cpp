#include <iostream>
#include <vector>
using namespace std;
void print_b(vector<vector<string>> &b) // function to print the board
{
    for (long unsigned int i = 0; i < b.size(); i++)
    {
        for (long unsigned int j = 0; j < b[i].size(); j++)
        {
            cout << b[i][j].c_str();
        }
        cout << endl;
    }
}
