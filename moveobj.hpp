#pragma once
using namespace std;
void move(vector<vector<string>>& ,vector<vector<int>>& ,char, Avatar*);
int try_to_move(vector<vector<int>>& ,vector<vector<string>>& ,Werewolf **,int,int ,int);
int try_to_move(vector<vector<int>>& ,vector<vector<string>>& ,Vampire **,int , int,int);
void move_vampire(vector<vector<int>>&, vector<vector<string>>&  ,Vampire **,int, int ,int);
void move_werewolf(vector<vector<int>>& ,vector<vector<string>>& ,Werewolf **,int , int ,int);


void disappear(vector<vector<int>>& ,vector<vector<string>>& , Vampire **, int );
void disappear(vector<vector<int>>& ,vector<vector<string>>& , Werewolf **, int );

void w_heal(Werewolf **,int);
void v_heal(Vampire **,int);
void fight(vector<vector<int>>& ,vector<vector<string>>& ,Vampire **,Werewolf **,int,int,int);
void game_action(vector<vector<int>>& ,vector<vector<string>>& , Vampire **, Werewolf **,int,int,int);