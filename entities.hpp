#include <iostream>
using namespace std;




class Ancestor{
    int x,y;
    public:
        Ancestor();
        ~Ancestor();
        void set_pos(int x, int y);
        int  get_x() const;
        int get_y() const;
};





class Avatar: virtual  public Ancestor{
    int healing;
    char side;
    public:
        Avatar();
        Avatar(int new_x, int new_y,char new_side);
        ~Avatar();
        void set_side(char new_side);
        char get_side() const;
       void  set_healing(int new_healing);
       int get_healing()const ;
};


class Creatures: virtual public Ancestor{
    int health;
    int medical;
    int power;
    int defense;
    public:
        Creatures();
        Creatures(int new_x, int new_y, int new_medical, int new_power,  int new_defense);
        virtual ~Creatures();
        virtual void move(int rows, int columns);
        void set_health(int new_health);
        void set_medical(int new_medical);
        int get_health() const;
        int get_medical() const;
        int get_power() const;
        int get_defense() const;
};

class Werewolf:virtual public Ancestor,public Creatures{
    public:
        static int w_population;
        Werewolf();
        Werewolf(int new_x, int new_y,int new_medical, int new_power,int new_defense);
        ~Werewolf();
        void move(int rows, int columns);
};

class Vampire:virtual public Ancestor,public Creatures{
    public:
        static int v_population;
        Vampire();
        Vampire(int new_x, int new_y,int new_medical, int new_power, int new_defense);
        ~Vampire();        
        void move(int rows, int columns);
};

